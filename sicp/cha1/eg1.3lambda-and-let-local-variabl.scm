(define (abs x) (if (> 0 x) (- x) x))

(define (half-interval-method f a b)
  (if (< 0
         (* (f a) (f b)))
      -1
        (let ((mid (/ (+ a b) 2.0)))
          (if (> 0.001
                (abs (f mid)))
              mid
              (if (> 0
                     (* (f a) (f mid)))
                  (half-interval-method f a mid)
                  (half-interval-method f mid b))))))

(half-interval-method (lambda (x) (- 32 (* 4 x))) (- 1) 10)
