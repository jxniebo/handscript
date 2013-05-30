;;;Below is manipulating definition of list&tree


;;Given list-t as test list (1 2 3 4 5)
;;Given tree-t as test tree (
(define list-t (list 1 2 3 4 5))
(define tree-t (list (list 1 (list 2 3)) (list (list 4 5))))


;;list manipulate procedure
;list reference by index
(define (list-ref list index)
  (if (= 0 index)
      (car list)
      (list-ref (- index 1) (cdr list))))

;appends item to the tail of list
(define (list-append list item)
  (cons list item))

;inserts item at the head of list
(define (list-ahead list item)
  (cons item list))

;joins two lists
;list1 and list2 should both be pair type
(define (list-join list1 list2)
  (cond ((null? list1) (list2))
        ((null? (cdr list1)) (cons (car list1) list2))
        (else (cons (car list1) (list-join (cdr list1) list2)))))

;inserts item at position index of list and returns list
;index should be limited in [0 length-1]
(define (list-insert list item index)
  (if (= 0 index)
      (list-ahead list item)
      (cons (car list) (list-insert (cdr list) item (- index 1)))))

;returns length of list
(define (list-length list)
  (if (null? list)
      0
      (+ 1 (list-length (cdr list)))))

;deletes item whose position in list is index
(define (list-del list index)
  (if (<= (list-length list) index)
      (error "out of arrange")
      (if (= 0 index)
          (cdr list)
          (cons (car list) (list-del (cdr list) (- index 1))))))

;replaces list[index] with item using existed procedure
(define (list-replace list item index)
  (list-insert (list-del list index) item index))

;replaces list[index] with item using basic expression which faster
(define (list-replace-v2 list item index)
  (if (<= (list-length list) index)
      (error "out of range")
      (if (= index 0)
          (cons item (cdr list))
          (cons (car list)
                (list-replace-v2 (cdr list) item (- index 1))))))


;;tree manipulate procedure
(define (count-leaves tree)
  (cond ((null? tree) 0)
         ((not (pair? tree)) 1)
         (else (+ (count-leaves (car tree))
                  (count-leaves (cdr tree))))))

;;test
(list-append list-t 6)
(list-insert list-t 1 3)
(list-join list-t list-t)
(list-length list-t)
(list-del list-t 3)
(list-replace list-t 44 3)
(list-replace-v2 list-t 43 4)
(count-leaves tree-t)
(display "End Test")
