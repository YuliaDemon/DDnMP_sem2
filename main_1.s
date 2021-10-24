   AREA |.text|, CODE, READONLY
array_zapis	PROC	; Начало функции array_sum_asm
	EXPORT array_zapis
     MOV R1,#0
ZAPIS
    CMP R1,R3
    BEQ exit
    LDR R5,[R0,R1]; ЗАПИСЫВАЕМ В R5 
    STR R5,[R2,R1]
    ADD R1,#4
    B ZAPIS
exit
	BX LR
	ENDP	; Конец функции array_sum_asm
       
array_treatment_asm	PROC	; Начало функции array_treatment_asm
	EXPORT array_treatment_asm
		; Функция (процедура) реализует обработку массива в соответствии с заданием 
		; Функция принимает указатель на массив через регистр R0,
		; размер массива через регистр R1,
		; указатель на пустой массив через регистр R2
		; R0 = *array
		; R1 = size(array)
		; R2 = *new_array	
	MOV R3, #0	
VVOD 
      CMP R3,R1       ;R3-i 
	  BGT EXIT_FUCTION
      LDR R5,[R0,R3]; ЗАПИСЫВАЕМ В R5      
      CMP R5,#0
      BEQ EXIT_FUCTION
      ADD R3,#4
	  B VVOD
	; Вызываем процедуру вычисления суммы массива
    
EXIT_FUCTION
    PUSH {R0-R3, LR}	; записываем все необходимые регистры в стек
    BL array_zapis
    POP {R0-R3, LR}
 	BX LR	; Возвращаемся назад по адресу расположенному в регистре LR
	ENDP	; Конец функции array_treatment_asm
	END		; Конец файла
        