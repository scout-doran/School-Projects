
.386

.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE debug.h
INCLUDE sqrt.h
INCLUDE io.h

.STACK  4096           

.DATA                   

; declare these first so that they are all on WORD boundaries

eye_x       WORD    ?
eye_y       WORD    ?
eye_z       WORD    ?

eyexprompt      BYTE    "Enter the x-coordinate of the camera eyepoint:  ", 0
eyeyprompt      BYTE    "Enter the y-coordinate of the camera eyepoint:  ", 0
eyezprompt      BYTE    "Enter the z-coordinate of the camera eyepoint:  ", 0


display         	BYTE    50 DUP (?), 0 ; the text to display in (x, y, z) format
output_u        	BYTE    "u: ", 0
output_v        	BYTE    "v: ", 0
output_n        	BYTE    "n: ", 0

eol             		BYTE    CR, LF, 0     ; end of line


atPoint_x  WORD  ?      ;get_and_display variables
atPoint_y  WORD  ?      ;get_and_display variables
atPoint_z  WORD  ?      ;get_and_display variables

atPointxprompt      BYTE    "Enter the x-coordinate of camera look at point:  ", 0
atPointyprompt      BYTE    "Enter the y-coordinate of camera look at point:  ", 0
atPointzprompt      BYTE    "Enter the z-coordinate of camera look at point:  ", 0


up_x  WORD  ?    ;get_and_display variables
up_y  WORD  ?    ;get_and_display variables
up_z  WORD  ?    ;get_and_display variables

up_xprompt      BYTE    "Enter the x-coordinate of the camera up direction:  ", 0
up_yprompt      BYTE    "Enter the y-coordinate of the camera up direction:  ", 0
up_zprompt      BYTE    "Enter the z-coordinate of the camera up direction:  ", 0



compute_n_x  WORD  ?    ;gets the sum to subtract and compute n
compute_n_y  WORD  ?    ;gets the sum to subtract and compute n
compute_n_z  WORD  ?    ;gets the sum to subtract and compute n

ndotn  WORD  ?          ;define ndotn
vdot  WORD  ?           ;variable for v

coordinate1  WORD  ?    ;new coordinates
coordinate2  WORD  ?    ;new coordinates
coordinate3  WORD  ?    ;new coordinates

u_x  WORD  ?    ;
u_y  WORD  ?    ;
u_z  WORD  ?    ;

length_u  WORD  ?    ;gets the length
length_v  WORD  ?    ;gets the length
length_n  WORD  ?    ;gets the length


.CODE          

getCoord    MACRO   prompt, var
               inputW  prompt, var
               mov     var, ax         ; store the result in memory
               outputW ax
            ENDM


get_and_display MACRO prompt1, prompt2, prompt3, prompt4, x1, x2, x3
                  getCoord prompt1, x1       
                  ;TO DO rest of relevant statements
                  getCoord prompt2, x2
		  getCoord prompt3, x3		  

                  printPoint prompt4, x1, x2, x3  
                ENDM                            

;Remember that to do output a word without using debug.h it has to be turned into a byte array using itoa
printPoint  MACRO   point, xvar, yvar, zvar
               output eol
               mov     point, "("
               itoa    point + 1, xvar ; convert xvar to digits and place after the "("
               mov     point + 7, ","  ; insert the comma after the digits for xvar
;-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
               itoa    point + 8, yvar 
               mov     point + 14, ","  

               itoa    point + 15, zvar
               mov     point + 21, ")"
               output point
               output eol		   
			   
			   
            ENDM

; This will use the vector length macro. The square root of the dot product is
;  equal to the length of the vector and to normalize each part of the coordinate will be divided
;  by the length. {x1 / length, y1 / length, z1 / length}
printNormPoint  MACRO   point, xvar, yvar, zvar, len
               itoa point + 5, len
               itoa point + 16, len
               itoa point + 27, len

               output eol
               mov     point + 0, "("

               itoa    point + 1, xvar  
               mov     point + 7, "/"  
               mov     point + 11, ","
;-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
	       itoa    point + 12, yvar
               mov     point + 18, "/"
               mov     point + 22, ","
               
               itoa    point + 23, zvar
               mov     point + 29, "/"
               mov     point + 33, ")"
	       		   
               output  point
               output  eol
            ENDM

; computes the dot product of two vectors
;  (x1 * x2) + (y1 * y2) + (z1 * z2)
dot_product MACRO   x1, y1, z1, x2, y2, z2
               mov ax, x1
               mov bx, x2
               imul bx        ; x1 * x2 is in ax  (actually dx::ax, high order bits dropped)
               mov cx, ax     ; the accumulating result will be in cx
;----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
               mov ax, y1
               mov bx, y2
               imul bx        ; y1 * y2 is in ax  (actually dx::ax, high order bits dropped)
               mov bx, ax     
               add cx, bx     ; ADD BX TO CX 
               
               mov ax, z1
               mov bx, z2
               imul bx        ; z1 * z2 is in ax  (actually dx::ax, high order bits dropped)
               add ax, cx     ; ADD CX TO AX  
               mov cx, ax
            ENDM

; computes the cross product of two vectors
;   a x b (a cross b) =
;    (a_y * b_z) - (a_z * b_y) (the first component (x) of a x b)
;    (a_z * b_x) - (a_x * b_z) (the second component (y) of a x b)
;    (a_x * b_y) - (a_y * b_x) (the third component (Z) of a x b)
cross_product MACRO   x1, y1, z1, x2, y2, z2, x3, y3, z3
        ;(y1*z2) - (z1*y2)
               mov ax, y1
               mov bx, z2
               mul bx         ; result in dx::ax
               mov cx, ax

               mov ax, z1     
               mov bx, y2
               mul bx         ; result in dx::ax
               neg ax

               add ax, cx
               mov x3, ax
;-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
        ;(z1 * x2) - (x1 * z2)
               mov ax, z1
               mov bx, x2
               mul bx
               mov cx, ax 
               
               mov ax, x1
               mov bx, z2
               mul bx
               neg ax
               
               add ax, cx
               mov y3, ax
        ;(x1 * y2) - (y1 * x2)
               mov ax, x1
               mov bx, y2
               mul bx
               mov cx, ax 
               
               mov ax, y1
               mov bx, x2
               mul bx
               neg ax
               
               add ax, cx
               mov z3, ax
            ENDM

; performs point-point subtraction to obtain a vector
; coordinate_1 – coordinate_2 = { x1 – x2, y1 – y2, z1 - z2 }
point_subtract MACRO x1, y1, z1, x2, y2, z2, vx, vy, vz
                  mov ax, x1
                  mov bx, x2
                  sub ax, bx
                  mov vx, ax
;-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
                  mov ax, y1
                  mov bx, y2
                  sub ax, bx
                  mov vy, ax

                  mov ax, z1
                  mov bx, z2
                  sub ax, bx
                  mov vz, ax		  
				  
               ENDM

; performs point-vector addition to obtain a new point
; coordinate_1 + coordinate_2 = { x1 + x2, y1 + y2, z1 + z2 }
point_vector_add MACRO x, y, z, vx, vy, vz, xn, yn, zn
                  mov ax, x
                  mov bx, vx
                  add ax, bx
                  mov xn, ax
;-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
                  mov ax, y
                  mov bx, vy
                  add ax, bx
                  mov yn, ax

                  mov ax, z
                  mov bx, vz
                  add ax, bx
                  mov zn, ax
                  
               ENDM


				  
; This macro will use the dot product to find the vector length. 
; The vector length is the square root of the dot product				  
vector_length	MACRO x, y, z	   
;-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
	           dot_product x,y,z,x,y,z         ; sqaure root is returned in ax    		   
		        sqrt cx		   
                ENDM



_start:
  
               get_and_display eyexprompt, eyeyprompt, eyezprompt, display, eye_x, eye_y, eye_z      ; location of the camera in world coordinates 
               get_and_display atPointxprompt, atPointyprompt, atPointzprompt, display, atPoint_x, atPoint_y, atPoint_z  ; location that the came is pointed at
               get_and_display up_xprompt, up_yprompt, up_zprompt, display, up_x, up_y, up_z         ; direction is up for the camera
               
;-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
;-----------------------------------------------------------------------------------------------
               ; calculate n 
               ;  subtract the at point from the eye point (E - A) coordinate by coordinate
               point_subtract eye_x, eye_y, eye_z, atPoint_x, atPoint_y, atPoint_z, compute_n_x, compute_n_y, compute_n_z 
                        
               ; define ndotn
               dot_product compute_n_x, compute_n_y, compute_n_z, compute_n_x, compute_n_y, compute_n_z
               mov ndotn, cx

               ; find (n.n)v = -(vup.n)n + (n.n)vup    
               
               ; compute -(vup.n)n and add to previous
               dot_product up_x, up_y, up_z, compute_n_x, compute_n_y, compute_n_z
               mov vdot, cx
               neg vdot
               mov ax, vdot
               mov bx, compute_n_x
               imul bx
               mov coordinate1, ax
               mov ax, vdot
               mov bx, compute_n_y
               imul bx
               mov coordinate2, ax
               mov ax, vdot
               mov bx, compute_n_z
               imul bx
               mov coordinate3, ax

               ; compute (n.n)vup
               mov ax, ndotn
               mov bx, up_x
               imul bx
               add coordinate1, ax
               mov ax, ndotn
               mov bx, up_y
               imul bx
               add coordinate2, ax
               mov ax, ndotn
               mov bx, up_z
               imul bx
               add coordinate3, ax
               
                  
               ; calculate cross_product of v and n to get u 
               cross_product coordinate1, coordinate2, coordinate3, compute_n_x, compute_n_y, compute_n_z, u_x, u_y, u_z      
               ; calculate the vector lengths of u, v and n 
               vector_length u_x, u_y, u_z
               mov length_u, ax
               vector_length coordinate1, coordinate2, coordinate3
               mov length_v, ax
               vector_length compute_n_x, compute_n_y, compute_n_z
               mov length_n, ax
               
               
               output eol
               output eol
               output output_u
               printNormPoint display, u_x, u_y, u_z, length_u
               
      ;-----------------------------------------------------------------------------------------------
      ; TO DO  // rest of the relevant statements
      ; Hint:

               ; print the rest of the points
      ;-----------------------------------------------------------------------------------------------
               output output_v
               printNormPoint display, coordinate1, coordinate2, coordinate3, length_v

               output output_n
               printNormPoint display, compute_n_x, compute_n_y, compute_n_z, length_n


        INVOKE  ExitProcess, 0  ; exit with return code 0

PUBLIC _start                   ; make entry point public

END                             ; end of source code