(define (curt x)
  (newton-curt-approximate 1.0 x))

(define (newton-curt-approximate y x)
  (if (good-enough y x)
      y
      (newton-curt-approximate (approximate y x) x)))

(define (good-enough y x)
  (> 0.001
     (abs (- x (cube y)))))

(define (approximate y x)
  (/ (+ (/ x (* y y)) (* 2 y))
     3))

(define (abs x)
  (if (> 0 x)
      (- x)
      x))

(define (cube x)
  (* x x x))

(curt 28)


;procedure abstraction for n root
(define (abstract-n-root depth radicand)
  (newton-n-root-approximate depth 1.0 radicand))

(define (newton-n-root-approximate depth guess radicand)
  (if (n-depth-good-enough depth guess radicand)
      guess
      (newton-n-root-approximate depth
                                 (n-depth-improve depth guess radicand) radicand)))

(define (n-depth-good-enough depth guess radicand)
  (> 0.01
          (abs (- radicand (n-depth-square depth guess)))))

(define (n-depth-improve depth guess radicand)
  (/ (+ (/ radicand (n-depth-square (- depth 1) guess))
        (* (- depth 1) guess))
     depth))

(define (n-depth-square depth value)
  (if (= 1 depth)
      value
      (* value (n-depth-square (- depth 1) value))))

(define (abs x)
  (if (> 0 x)
      (- x)
      x))

(abstract-n-root 2 28)
(abstract-n-root 3 28)
(abstract-n-root 4 28)
(abstract-n-root 5 28)
