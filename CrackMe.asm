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

                mov  ax, 4c00h                  ; DOS Fn 4ch = exit (al)
                int  21h

;------------------------------------------------------------------------------
; ReadPassword  func to read password from stdin to buffer
; Entry:
; Exit:
; Destroy:
;------------------------------------------------------------------------------
ReadPassword    proc
                mov  ah, 07h                    ; DOS Fn 07H = No echo
                                                ; unfiltered console input
                int  21h                        ; call Fn 07H
                                                ; al = input symbol
                mov  bx, 0b800h                 ; bx = videoseg
                mov  es, bx                     ; es = bx

                mov  ah, 66h                    ; blue color
                mov  di, 80 * 5 * 2 + 20 * 2    ; offset

                stosw

                ret
ReadPassword    endp
;------------------------------------------------------------------------------

End             Start
;------------------------------------------------------------------------------
