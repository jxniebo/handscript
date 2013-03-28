;define balance in global scope
(define balance 100)
(define (withdraw value)
  (if (< balance value)
      "not sufficient"
      (begin (set! balance (- balance value))
             balance)))

;define balance in local scope would not get expect result
(define (new-withdraw value)
  (let ((balance 100))
    (if (< balance value)
        "not sufficient"
        (begin (set! balance (- balance value))
             balance))))

;define a procedure to return a lambda procedure with its balance initiated
;and we can procedure a and b totally independent withdraw procedure by
;define a make-withdraw 100
;define b make-withdraw 100
(define (make-withdraw balance)
  (lambda (value)
    (if (< balance value)
        "not sufficient"
        (begin (set! balance (- balance value))
               balance))))


;how to create an account? with withdraw and deposit procedure in it?
;we should call some procedure, then this procedure has an defined
;balance and operation procedures
(define (make-account balance)
  (define (withdraw value)
      (if (< balance value)
      "not sufficient"
      (begin (set! balance (- balance value))
             balance)))
  (define (deposit value)
    (begin (set! balance (+ balance value))
           balance))
  (define (dispatch m value)
    (cond ((eq? m 'withdraw) (withdraw value))
          ((eq? m 'deposit) (deposit value))
          (else (error "unknown operation"))))
  dispatch)
