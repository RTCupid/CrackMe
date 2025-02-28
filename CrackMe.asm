;------------------------------------------------------------------------------
;                        Asm Task to Crack somebody
;                         (c) 2025 Muratov Artyom
;------------------------------------------------------------------------------

.model  tiny
.code
org     100h

Start:
                call ReadPassword               ; read password from
                                                ; stdin to check it
                mov  ah, 09h                    ;-----------------------
                lea  si, InputPassword          ;                      |
                mov  cx, 11                     ; attributes for       |
                mov  di, 80 * 2 * 10 + 15 * 2   ;       string         |
                mov  bx, 0b800h                 ;                      |
                mov  es, bx                     ;-----------------------

                call PutString                  ; output string to videoseg


                mov  ax, 4c00h                  ; DOS Fn 4ch = exit (al)
                int  21h

;------------------------------------------------------------------------------
; ReadPassword  func to read password from stdin to buffer
; Entry:        None
; Exit:         InputPassword - buffer from stdin
; Destroy:      cx, ax, di,
;------------------------------------------------------------------------------
ReadPassword    proc
                mov  cx, 11                     ; cx = number of symbols
                                                ; in password
                mov  di, offset InputPassword   ; offset
                mov  ah, 07h                    ; DOS Fn 07H: No echo
                                                ; unfiltered console input
NewChar:
                int  21h                        ; call Fn 07H
                                                ; al = input symbol
                mov  cs:[di], al                ; write to buffer InputPassword
                inc  di                         ; di++

                loop NewChar                    ; while (--cx) goto NewChar
                mov  byte ptr cs:[di], '$'      ; write to InputPassword
                                                ; end symbol '$'
                ret
ReadPassword    endp
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
; PutString  Func to make string of frame
; Entry:        ah     - color of string
;               si     - array of symbol for string
;               cx     - len of string
;               di     - start of print string
;               es     - videoseg
; Exit:         None
; Destroy:      di, si, al
;------------------------------------------------------------------------------
PutString    proc

NewSymbolStr:
                lodsb                           ; ax = first symbol of string
                                                ; mov al, ds:[si] && inc si
                stosw                           ; mov es:[di], ax && di += 2

                loop NewSymbolStr               ; while (--cx) goto NewSymbolStr

                ret
PutString       endp

;------------------------------------------------------------------------------
AdminPasswordLen db 11

InputPassword   db  12 dup ('s')

AdminPassword   db  "POLTORASHKA"

End             Start
;------------------------------------------------------------------------------
