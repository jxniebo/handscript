;; This buffer is for notes you don't want to save, and for Lisp evaluation.
;; If you want to create a file, visit that file with C-x C-f,
;; then enter the text in that file's own buffer.

(define (p) (p))
(define (test x y)
  (if (= 0 x)
      0
    y))
(test 0 (p))
