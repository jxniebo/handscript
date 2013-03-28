(define (sqrt y)
  (newton-sqrt-approximate 1.0 y))

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

(sqrt 34)
