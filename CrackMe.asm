;------------------------------------------------------------------------------
;                        Asm Task to Crack somebody
;                         (c) 2025 Muratov Artyom
;------------------------------------------------------------------------------

.model  tiny
.code
org     100h

Start:
                call PasswordVerify             ; Start verify

                mov  ax, 4c00h                  ; DOS Fn 4ch = exit (al)
                int  21h

;------------------------------------------------------------------------------
; PasswordVerify func to request a password and verify it
; Entry:        None
; Exit:         None
; Destroy:      ax, bx, dx
;------------------------------------------------------------------------------
PasswordVerify  proc
                mov  bx, 0FF00h                 ; bx = 0
Retry:
                lea  dx, AskPassword            ; dx = request a password
                call PutString                  ; output string to consol

;---------------Input-Password-------------------------------------------------
                push bx                         ; save bx in stack
                call ReadPassword               ; read password from
                                                ; stdin to verify it
                pop  bx                         ; back bx from stack

;---------------Check-Is-Quit-Or-Not-------------------------------------------
                cmp  IsQuit, 1                  ; if (IsQuit = 1) {
                je   UnLuckVerify               ; goto UnLuckVerify }

;---------------End-Check------------------------------------------------------

                call CursorNewString            ; make cursor to new string

                mov  ax, bx                     ; ax = bx
                mov  cx, 12                     ; cx = 12 (len of password)
                call Verify                     ; compare strings InputPassword
                                                ; and AdminPassword with len cx
                                                ; bx += 1, if password is
                                                ; incorrect
                cmp  bx, ax                     ; if (bx > ax) {
                ja   Retry                      ; goto Retry }

                lea  dx, HelloAdmin             ; if password is right
                call PutString                  ; "Hi, you got Admin rights!$"
                call CursorNewString            ; make cursor to new string
UnLuckVerify:

                ret
PasswordVerify  endp

;------------------------------------------------------------------------------
; CursorNewString func to make cursor to new string
; Entry:        None
; Exit:         None
; Destroy:      ah, dl
;------------------------------------------------------------------------------
CursorNewString proc
                mov  ah, 02h                    ; Dos Fn 02h = Display Output
                mov  dl, 13                     ; CR (cursor to the beginning
                                                ; of the line)
                int  21h
                mov  dl, 10                     ; LF (cursor to next line)
                int  21h

                ret
CursorNewString endp

;------------------------------------------------------------------------------
; Verify        func to compare strings InputPassword and AdminPassword
; Entry:        cx  = len of password
;               bx  = old value of bx
; Exit:         bx  = old value of bx, if password is correct
;               bx += 1, if password is incorrect
; Destroy:      bx (may be), si, di, DF, cx
;------------------------------------------------------------------------------
Verify          proc
                cld                             ; DF = 0 (forward)
                lea  si, InputPassword          ; preparation
                lea  di, AdminPassword          ; for cmpsb

                repe cmpsb                      ;  cmp while equal
                                                ; (max cx symbols)
                                                ; if (strings is different) {
                je   Equal                      ; goto NoEqual }
                inc  bx                         ; bx += 1 anyway
Equal:
                ret
Verify          endp

;------------------------------------------------------------------------------
; ReadPassword  func to read password from stdin to buffer
; Entry:        None
; Exit:         InputPassword - buffer from stdin
; Destroy:      cx, ax, di, dx, bx
;------------------------------------------------------------------------------
ReadPassword    proc
                mov  cx, 15                     ; cx = number of symbols
                                                ; in password
                mov  di, offset InputPassword   ; offset
NewChar:
                mov  ah, 07h                    ; DOS Fn 07H: No echo
                                                ; unfiltered console input
                int  21h                        ; call Fn 07H
                                                ; al = input symbol
;---------------Check-[q]-quit-----------------------------------------
                cmp  al, 'q'                    ; if (al != 'q') {
                jne  ContinueInput              ; goto ContinueInput }
                mov  IsQuit, 1                  ; IsQuit = 1
                jmp  EndInput                   ; goto EndInput
;---------------Check-[q]-quit-----------------------------------------
ContinueInput:
;---------------Check-Enter--------------------------------------------
                push ax                         ; save ax in stack
                in   al, 60H                    ; read scan code from PPI port
                                                ; al = symbol from 60H port
                mov  bl, al                     ; bl = al
                pop  ax                         ; back ax from stack
                cmp  bl, 1ch                    ; if (al = 'Enter') {
                je   EndInput                   ; goto EndInput }
;---------------End-Check-Enter----------------------------------------
                mov  cs:[di], al                ; al to buffer InputPassword
                inc  di                         ; di++
                                                ;----------------------------
                mov  ah, 02h                    ; DOS Fn 02h Display output |
                                                ; write '*' when user       |
                mov  dl, '*'                    ; write symbol              |
                int  21h                        ;----------------------------

                loop NewChar                    ; while (--cx) goto NewChar
EndInput:
                ret
ReadPassword    endp

;------------------------------------------------------------------------------
; PutString  Func to make string of frame
; Entry:        dx     - offset  array of symbol for string
; Exit:         None
; Destroy:      ah
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
AdminPasswordLen db 12

HelloAdmin      db  "Hi, you got Admin rights!$"

AskPassword     db  "Enter the password or [q]: $"

Isquit          db  0

InputPassword   db  15 dup ('s')

AdminPassword   db  "KOGORTASPIRT"

End             Start
;------------------------------------------------------------------------------
