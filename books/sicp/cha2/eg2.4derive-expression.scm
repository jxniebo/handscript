;;;Below is the steps to construct a procedure for deriving expressions
;;;Accepts expression of symbols in quoted list like '(+ a b) and
;;;a symbol for deriving
;;;Returns a quoted list which contains expression that has been derived

;;Given small procedure to break down the procedure

;(variable? e) whether e is a variable
(define (variable? e) (symbol? e))

;whether e1 is the same variable of e2
(define (same-variable? e1 e2)
  (and (variable? e1) (variable e2) (eq? e1 e2)))

;whether e is a sum expression like '(+ a b)
(define (sum? e)
  (and (pair? e) (eq? (car e) '+)))

;(addend e) extract the addend of e
(define (addend e) (cadr e))

;(augend e) extract the augend of e
(define (augend e) (caddr e))

;(make-sum e1 e2) construct a sum expression by e1 e2
(define (make-sum e1 e2) (list '+ e1 e2))

;(product? e) whether e is a multiply expression
(define (product? e) (and (pair? e) (eq? (car e) '*)))

;(multiplier e) extract the multiplier of e
(define (multiplier e) (cadr e))

;(multiplicand e) extract the multiplicand of e
(define (multiplicand e) (caddr e))

;(make-product e1 e2) construct multiply expression by e1 e2
(define (make-product e1 e2) (list '* e1 e2))

;(number? e1) whether e is a number


;;compose those small procedures into deriving procedure
;(derive exp var)
;Accepts an expression in form of symbol list like (* a b)
;and a variable for deriving
;Returns a derived expression in the form of symbol list
;number? 0
;same-variable? 1
;sum? (make-sum addend augend)
;product? (make-product multiplier multiplicand)
;others? error
(define (derive exp  var)
  (cond ((number? exp) 0)
        ((same-variable? exp var) 1)
        ((sum? exp)
         (make-sum (derive (addend exp) var)
                   (derive (augend exp) var)))
        ((product? exp)
         (make-sum
          (make-product (multiplier exp)
                        (derive (multiplicand exp) var))
          (make-product (multiplicand exp)
                        (derive (multiplier exp) var))))
        (else (error 'unknow expression exp))))

;;;need to extend this procedure
;;first step to write them in human form
;(human-form result)
;variable? variable
;number? number
;sum? (list addend '+ augend)
;product? (list multiplier '* multiplicand)
(define (human-form result)
  (cond ((variable? result) result)
        ((number? result) result)
        ((sum? result)
         (list (human-form (addend result))
               '+
               (human-form (augend result))))
        ((product? result)
         (list (human-form (multiplier result))
               '*
               (human-form (multiplicand result))))
        (else (error 'failure occurred))))

;step two to make the result more reasonable
;rewrite (make-product)
;if product
;case (* x 0) 0
;case (* x 1) x
;case (* number number) calculate product
;TODO case (* x a) ax
;TODO case (* x x) x^2
(define (make-product e1 e2)
  (cond ((or (eq? e1 0) (eq? e2 0)) 0)
        ((eq? e1 1) e2)
        ((eq? e2 1) e1)
        ((and (number? e1) (number? e2))
         (* e1 e2))
        (else (list '* e1 e2))))

;rewrite (make-sum)
;if sum
;case (+ x 0) x
;case (+ number number) calculate sum
(define (make-sum e1 e2)
  (cond ((eq? e1 0) e2)
        ((eq? e2 0) e1)
        ((and (number? e1) (number? e2))
         (+ e1 e2))
        (else (list '+ e1 e2))))
;else error
