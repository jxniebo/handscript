;;;Below is data abstraction example for manipulating rational number
;Given 'make-rat <n> <d>' as constrcture which returns a rational
;  number with n as numerator and d as denominator
;Given 'numer <x>' as selector for numerator
;Given 'denom <x>' as selector for denominator

;bind constructor and selector with built-in procedure
(define (make-rat n d) (cons n d))
(define (numer x) (car x))
(define (denom x) (cdr x))

;rational number display
(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))


;rational number add
(define (add-rat x y)
  (make-rat (+ (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

;rational number subtract
(define (sub-rat x y)
  (make-rat (- (* (numer x) (denom Y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

;rational number multiply
(define (mul-rat x y)
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))

;rational number divide
(define (div-rat x y)
  (make-rat (* (numer x) (denom Y))
            (* (numer y) (denom x))))

;rational number is-equal
(define (is-equal-rat x y)
  (= (* (numer x) (denom y))
     (* (numer y) (denom x))))




;test
(define one-half (make-rat 1 2))
(print-rat one-half)
(define one-third (make-rat 1 3))
(print-rat one-third)
(print-rat (add-rat one-half one-third))
(print-rat (sub-rat one-half one-third))
(print-rat (mul-rat one-half one-third))
(print-rat (div-rat one-half one-third))
(is-equal-rat one-half one-third)
