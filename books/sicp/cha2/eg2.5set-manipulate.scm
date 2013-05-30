;;;Below is a new data structure set and the operations on it.
;;;Then do something with it.
;;;Set is a list container in which no items are same.

;;Given some operations
;(element-of-set set item) is item an element of set?
(define (element-of-set set item)
  (cond ((null? set) false)
        ((equal? (car set) item) true)
        (else (element-of-set (cdr set) item))))

;(adjoin-set set item) if set not contain item then add it
(define (adjoin-set set item)
  (if (element-of-set set item)
      set
      (cons item set)))

;(intersection-set set1 set2) return items which are in both sets
(define (intersection-set set1 set2)
  (if (null? set2)
      ()
      (if (element-of-set set1 (car set2))
          ;adjoin-set would check element-of-set again, so it's bad
          ;(adjoin-set (intersection-set set1 (cdr set2)) (car set2))
          (cons (car set2) (intersection-set set1 (cdr set2)))
          (intersection-set set1 (cdr set2)))))

;(union-set set1 set2) combine two sets together and distinct
(define (union-set set1 set2)
  (if (null? set2)
      set1
      (if (element-of-set set1 (car set2))
          (union-set set1 (cdr set2))
          (adjoin-set (union-set set1 (cdr set2)) (car set2)))))


;;Notice that the time complexity of above operations is huge
;;And these operations can be improved if items are ordered in set
(define (element-of-set-in-order set item)
  (cond ((= item (car set)) true)
        ((< item (car set)) false)
        (else (element-of-set-in-order (cdr set) item))))

(define (intersection-set-in-order set1 set2)
  (cond ((or (null? set1) (null? set2)) ())
        ((= (car set1) (car set2))
         (cons (car set1)
               (intersection-set-in-order (cdr set1) (cdr set2))))
        ((< (car set1) (car set2))
         (intersection-set-in-order (cdr set1) set2))
        (else (intersection-set-in-order set1 (cdr set2)))))

(define (adjoin-set-in-order set item)
  (cond ((null? set) (list item))
        ((<= item (car set)) (cons item set))
        (else (cons (car set) (adjoin-set-in-order (cdr set) item)))))

(define (union-set-in-order set1 set2)
  (cond ((null? set1) set2)
        ((null? set2) set1)
        ((= (car set1) (car set2))
         (cons (car set1)
               (union-set-in-order (cdr set1) (cdr set2))))
        ((< (car set1) (car set2))
         (cons (car set1) (union-set-in-order (cdr set1) set2)))
        (else (cons (car set2)
                    (union-set-in-order set1 (cdr set2))))))



;;
