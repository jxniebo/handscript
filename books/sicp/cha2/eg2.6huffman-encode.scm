;;;Below would the usage of tree structure
;;;which would make data ordered and faster for access

;;First, let's construct a common binary tree with set
;;Each node of tree should be (value left-tree right-tree)
;;and value of each node must not be null

;Given (make-node value) node should be (value left right)
(define (make-node value)
  (if (not (null? value))
      (if (pair? value)
          value
          (list value () ()))
      (error 'value should not be null)))

;Given (append-tree root node)
;if tree is empty then item would be the root
;if value of node < root append left tree
;if value of node >= root append right tree
(define (append-tree tree item)
  (let ((node (make-node item)))
    (cond ((null? tree) node)
          ((< (car node) (car tree))
           (list (car tree)
                 (append-tree (cadr tree) node)
                 (caddr tree)))
          (else (list (car tree)
                      (cadr tree)
                      (append-tree (caddr tree) node))))))

;Should find a way to test if append-tree works
;let list-t contains the items we want to append
;if null? list-t ()
;else append deeper
(define (test-tree-append tree list-t)
  (if (null? list-t)
      tree
      (test-tree-append (append-tree tree (car list-t)) (cdr list-t))))

;SCIP book just reminder me that i made the procedure not useful for
;other data structure, though i use the make-node abstract, which is
;good, but i just use car node to get value instead of selectors


;;Next let's construct the Huffman tree
;;Huffman tree is used in encoding, the leaves of this tree is an
;;character needs encoding, each leaf encoded as the path to it
;;If leaf a has a path llrrlr it can be encoded to 001101
;;And Huffman provides a useful way to construct less code for a
;;sequence by the algorithm that use the frequency as weight,
;;the leave which heavier would be deeper in the tree
;;define data structure of nodes to be (weight contain left right)


;Given (make-Huffman-node weight value) to construct node
(define (make-Huffman-node weight value)
  (list weight value () ()))

(define (get-weight node)
  (car node))
(define (get-value node)
  (cadr node))
(define (left-tree node)
  (caddr node))
(define (right-tree node)
  (cadddr node))

;Given some compare procedures
(define (lighter? node1 node2)
  (if (< (get-weight node1) (get-weight node2))
      true
      false))

(define (contain? node char)
  (define (have? chars char)
    (cond ((or (null? chars) (null? char)) false)
          ((not (pair? chars)) (eq? chars char))
          (else (or (have? (car chars) char)
                    (have? (cdr chars) char)))))
  (have? (get-value node) char))


;to combine two nodes together until only one node
;left, which would be the root node. The step to combine two nodes is
;(sum wight, append contain, one node, another node)
(define (combine-node node1 node2)
  (list (+ (car node1) (car node2))
        (cons (cadr node1) (cadr node2))
        node1
        node2))

;Then we can construct Huffman tree now
;Given procedure (make-Huffman-tree node-list)
;assume node-list contained ascend order nodes
;need define an internal procedure to keep order
;null? node-list ()
;null? (cdr node-list) (car node-list)
;else (make-Huffman-tree (insert-order-list new-node rest-nodes))
(define (make-Huffman-tree node-list)
  (define (insert-Huffman-node node nodes)
    (cond ((null? nodes) (list node))
          (else (if (lighter? node (car nodes))
                    (cons node nodes)
                    (cons (car nodes)
                          (insert-Huffman-node node (cdr nodes)))))))
  (define (reduce-node node-list)
    (if (null? (cdr node-list))
        (car node-list)
        (reduce-node
         (insert-Huffman-node
          (combine-node (car node-list) (cadr node-list))
          (cddr node-list)))))

  (cond ((null? node-list) ())
        ((null? (cdr node-list))
         (reduce-node (cons (car node-list) ())))
        (else (reduce-node node-list))))



;Define procedure to encode chars from Huffman tree
;Give procedure to encode node (encode-node root char code)
;if root not contain char error info
;else update code
(define (leaf? node)
  (and (null? (left-tree node)) (null? (right-tree node))))

(define (encode-node root char code)
  (cond ((not (contain? root char)) (error "code not include"))
        ((leaf? root) code)
        ((contain? (left-tree root) char)
         (encode-node (left-tree root) char (format-code code 0)))
        (else
         (encode-node (right-tree root)
                           char
                           (format-code code 1)))))

(define (encode root char)
  (encode-node root char ()))

;Define procedure to decode chars form Huffman tree
;null? root error info
;null char return text
;leaf? root push character into text and go on
(define (decode root traveler code text)
  (cond ((null? root) (error "Huffman tree not build"))
        ((leaf? traveler) (decode root root code
                                  (append text (get-value traveler))))
        ((null? code) text)
        (else (if (= (car code) 0)
                  (decode root (left-tree traveler) (cdr code) text)
                  (decode root (right-tree traveler) (cdr code) text)))))



;;test
(define tree-t (make-Huffman-tree (list
                    (list 1 (list 'a) () ())
                    (list 2 (list 'b) () ())
                    (list 3 (list 'c) () ())
                    (list 3 (list 'd) () ())
                    (list 8 (list 'e) () ())
                    (list 9 (list 'f) () ()))))

(encode tree-t 'a)
(encode tree-t 'b)
(encode tree-t 'c)
(encode tree-t 'd)
(encode tree-t 'e)
(encode tree-t 'f)

(decode tree-t tree-t (list 0 0 0 1 0 1 1 1 0) ())
