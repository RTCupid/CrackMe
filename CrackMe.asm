;------------------------------------------------------------------------------
;                        Asm Task to Crack somebody
;                         (c) 2025 Muratov Artyom
;------------------------------------------------------------------------------

.model  tiny
.code
org     100h

Start:
                lea  dx, AskPassword            ; dx = request a password
                call PutString                  ; output string to consol

                call ReadPassword               ; read password from
                                                ; stdin to check it
                                                ;-----------------------
                lea  dx, InputPassword          ;  dx = string to put  |
                                                ;-----------------------
                call PutString                  ; output string to consol

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
; Entry:        dx     - offset  array of symbol for string
; Exit:         None
; Destroy:      di, si, al
;------------------------------------------------------------------------------
PutString       proc
                mov  ah, 09h                    ; DOS Fn 09h = puts(dx)

                int  21h                        ; call puts(dx)

                ret
PutString       endp

;------------------------------------------------------------------------------
; HashCounter   func to count hash of password
; Entry:        si = ptr to string of password
; Exit:         ax = hash of password
; Destroy:      si, ax,
;------------------------------------------------------------------------------
HashCounter     proc




                ret
HashCounter     endp

;------------------------------------------------------------------------------
AdminPasswordLen db 11

AskPassword     db  "Enter the password: $"

InputPassword   db  12 dup ('s')

AdminPassword   db  "POLTORASHKA"

End             Start
;------------------------------------------------------------------------------
