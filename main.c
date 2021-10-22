
#include <stdio.h>		/* Заголовочный файл объявляет несколько целочисленных типов и макросов */
#include <stdint.h>		/* Заголовочный файл объявляет несколько целочисленных типов и макросов */

// Инициализируем первичный массив с числами
int32_t array_original [] = {-1,5,1,2,0,1,7,6,7,8};

// Инициализируем, т.е. объявляем указатель на новый массив. Начальное значение NULL
int32_t* array = NULL;
	
// Объявляем прототип функции, которая будет выполнять задание
// Указываем на массив и размерность
int32_t* array_treatment (int32_t* array_ptr, size_t array_size);	//функция находит адр.0 и записывает значение до него в новый массив
	

int32_t array_upor (int32_t* array_ptr, size_t array_size, int32_t* zero_index);		
	
//Экспортируем функцию	из main.s написанную на ассемблере.
extern void array_treatment_asm (int32_t* array_ptr, size_t array_size, int32_t* new_array_ptr );	
	
int32_t new_array [sizeof(array_original)/sizeof(int32_t)]= {0};// делим на 10 ??????

int main (void)
{
    /*Вызываем функцию array_treatment. 
	Функция возвратит указатель на массив соответствующий заданию. 
	Размерность массива такая же как у оригинального массива.*/
    
	array = array_treatment(array_original, sizeof(array_original)/sizeof(int32_t));
	
	array_treatment_asm(array_original, sizeof(array_original), new_array); // переход в асемблер 

	while (1)
	{
	}
	return 0;
}
int32_t* array_treatment (int32_t* array_ptr, size_t array_size)
{
	int32_t *new_array = NULL;
	int32_t number_serial = 0;
	int32_t* znach0 = 0;
	//Выделяем область памяти для нового массива из кучи (heap).
	new_array =  (int32_t*) (malloc(array_size));
	
 while (number_serial<array_size)
   {
     if(array_ptr[number_serial]==0)
     {
     znach0=array_ptr+number_serial;
     number_serial=array_size;
     }
	 number_serial++;
   }
	 
    array_upor(new_array, array_size,znach0);
   
	return new_array;
}

int32_t array_upor (int32_t* new_array, size_t array_size,int32_t* zero_index)
{
	int32_t* j = (zero_index); // Вспомогательная переменная
	int32_t i = 0;              // порядковое значение
	int32_t* a=0;                // вспомогательная переменная
	while (a < (zero_index))  
	{
        
        *(new_array+i)=*(array_original+i);  // записываем значения с индексом a в новый массив
        i++;
        a=array_original+i;
}
}
/********************************************************************************/
