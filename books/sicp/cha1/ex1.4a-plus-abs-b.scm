(define (a-plus-abs-b-v1 a b)
  (+ a (cond ((< b 0) (- b))
             (else b))))


(define (a-plus-abs-b-v2 a b)
  ((cond ((< b 0) -)
         (else +))
   a b))


(define (a-plus-abs-b-v3 a b)
  (cond ((< b 0) (- a b))
        (else (+ a b))))


(a-plus-abs-b-v1 2 -2)
(a-plus-abs-b-v2 2 -2)
(a-plus-abs-b-v3 2 -2)
