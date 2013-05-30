(define (new-if-v1 exp value1 value2)
  (cond (exp value1)
        (else value2)))

(new-if-v1 (> 2 3) 4 3)

(define (sqrt y)
  (define (newton-sqrt-approximate x y)
    (if (good-enough x y)
        x
      (newton-sqrt-approximate (approximate x y) y)))
  (define (good-enough x y)
    (> 0.0001
       (abs (- y (* x x)))))
  (define (abs x)
    (if (< x 0)
        (- x)
      x))
  (define (approximate x y)
    (/ (+ x (/ y x))
       2))
  (newton-sqrt-approximate 1.0 y))

(sqrt 34)
;Value: 5.830951897587282


(define (sqrt-with-new-if y)
  (define (newton-sqrt-approximate x y)
    (new-if-v1 (good-enough x y)
        x
      (newton-sqrt-approximate (approximate x y) y)))
  (define (good-enough x y)
    (> 0.0001
       (abs (- y (* x x)))))
  (define (abs x)
    (if (< x 0)
        (- x)
      x))
  (define (approximate x y)
    (/ (+ x (/ y x))
       2))
  (newton-sqrt-approximate 1.0 y))

(sqrt-with-new-if 34)
;Aborting!: maximum recursion depth exceeded



;Value: new-if-v1
;Value: 3
;Value: sqrt
;Value: 5.830951897587282
;Value: sqrt-with-new-if
;Aborting!: maximum recursion depth exceeded

