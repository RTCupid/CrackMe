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

;---------------End-Check-Cursor-to-new-string---------------------------------

                call CursorNewString            ; make cursor to new string

                mov  dx, bx                     ; dx = bx

;---------------Count-Hash-and-Verify-Password---------------------------------

                lea  si, InputPassword          ; si  = InputPassword

                call HashCounter                ; Count hash InputPassword
                                                ; di = hash of InputPassword
                jmp  VerifyPassword             ; goto VerifyPassword

                InputPassword   db  15 dup ('S'); buffer with input password
VerifyPassword:
                mov  dx, bx                     ; dx = bx (for hacking)

                call Verify                     ; compare strings InputPassword
                                                ; and AdminPassword with len cx
                                                ; bx += 1, if password is
                                                ; incorrect
                cmp  bx, dx                     ; if (bx > dx) {
                ja   Retry                      ; goto Retry }

;---------------Giving-Admin-Rights--------------------------------------------

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
; Entry:        di  = hash of InputPassword
;               bx  = old value of bx
; Exit:         bx  = old value of bx, if password is correct
;               bx += 1, if password is incorrect
; Destroy:      bx (may be)
;------------------------------------------------------------------------------
Verify          proc
                cmp  di, AdminPassword          ; if (di = AdminPassword (hash)) {
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
                ;mov  word ptr cx, BufferLen     ; cx = number of symbols
                                                ; in password
                mov  di, offset InputPassword   ; offset
NewChar:
                mov  ah, 07h                    ; DOS Fn 07H: No echo
                                                ; unfiltered console input
                int  21h                        ; call Fn 07H
                                                ; al = input symbol
;---------------Check-[q]-quit-------------------------------------------------
                cmp  al, 'q'                    ; if (al != 'q') {
                jne  ContinueInput              ; goto ContinueInput }
                mov  IsQuit, 1                  ; IsQuit = 1
                jmp  EndInput                   ; goto EndInput
;---------------Check-[q]-quit-------------------------------------------------
ContinueInput:
;---------------Check-Enter----------------------------------------------------
                push ax                         ; save ax in stack
                in   al, 60H                    ; read scan code from PPI port
                                                ; al = symbol from 60H port
                mov  bl, al                     ; bl = al
                pop  ax                         ; back ax from stack
                cmp  bl, 1ch                    ; if (al = 'Enter') {
                je   EndInput                   ; goto EndInput }
;---------------Load-Input-Symbol-to-Buffer------------------------------------
                mov  cs:[di], al                ; al to buffer InputPassword
                inc  di                         ; di++
;---------------Write-*--------------------------------------------------------
                                                ;----------------------------
                mov  ah, 02h                    ; DOS Fn 02h Display output |
                                                ; write '*' when user       |
                mov  dl, '*'                    ; write symbol              |
                int  21h                        ;----------------------------

                jmp  NewChar                    ; goto NewChar
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
; Exit:         di = hash of password
; Destroy:      si, ax, di, cx
;------------------------------------------------------------------------------
HashCounter     proc
                xor  di, di                     ; di  = 0
                xor  ax, ax                     ; ax  = 0
                mov  word ptr cx, BufferLen     ; cx  = len buffer
HashCount:
                lodsb                           ; mov al, ds:[si] && inc si
                shr  ax, 4                      ; ax >> 4 (____0101)
                add  di, ax                     ; di += ax
                loop HashCount                  ; while (--cx) goto HashCount

                ret
HashCounter     endp

;------------------------------------------------------------------------------

BufferLen       dw  15

HelloAdmin      db  "Hi, you got Admin rights!$"

AdminPassword   dw  0045h

AskPassword     db  "Enter the password or [q]: $"

Isquit          db  0

End             Start
;------------------------------------------------------------------------------
