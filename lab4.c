#include <stdio.h> 
#define SIZE 5
//enum enumera una lista de palabras, de esta forma se puede hacer una pregunta cerrada al usuario
//de una forma mas rapida y facil y asi tambien eliminar el factor de que el usuario escriba mal el 
//nombre del dato que necesito 
enum enfasis {
	ELECTRONICA=1,
	REDES,
	POTENCIA,
	CONTROL
};
//con struct se crea una estructura en forma de vector fila donde puedo guardar distintas variables para programar 
//una lista de una forma mas ordenada y practica
struct datos_persona {
	char nombre[15];
	char apellido[15];
	int telefono;
	char carnet[10];
	enum enfasis Enfasis;
	
};

//se crean una funcion set que pida valores al usuario y que con el puntero del estruct los vaya almacenando en las 
//casillas correspondientes
void set_struct (struct datos_persona *ptr_struct, int selector){
	printf("\nDigite los datos del estudiante %d\n ",selector+1);
	printf("Digite su nombre.\n");
	scanf("%s", ptr_struct->nombre);
	printf("Digite su apellido.\n");
	scanf("%s", ptr_struct->apellido);
	printf("Digite su numero de telefono.\n");
	scanf("%d", &ptr_struct->telefono);
	printf("Digite su carnet.\n");
	scanf("%s", ptr_struct->carnet);
	
	printf("Elija el numero que corresponde a su enfasis:\n1.ELECTRONICA.\n2.REDES.\n3.POTENCIA.\n4.CONTROL.\n");
	int seleccion=0;
	scanf("%d", &seleccion);
		switch (seleccion){
			case 1:
				ptr_struct -> Enfasis = ELECTRONICA;
			break;
			case 2:
				ptr_struct -> Enfasis = REDES;
			break;
			case 3:
				ptr_struct -> Enfasis = POTENCIA;
			break;
			case 4:
				ptr_struct -> Enfasis = CONTROL;
			break;
			
		}//fin del switch
	
}//fin del set


//se crea una funcion print que imprima los datos de las casillas del struct tambien con ayuda del puntero
void print_struct (struct datos_persona *ptr_struct, int selector){
	printf("\nEstudiante %d: \n",selector+1);
	printf("\nNombre: %s", ptr_struct->nombre);
	printf("\nApellido: %s", ptr_struct->apellido);
	printf("\nNumero de telefono: %d", ptr_struct->telefono);
	printf("\nCarnet: %s", ptr_struct->carnet);
	
//como el enum da el numero de lugar donde está la palabra entonces aquí se pasa ese numero a el dato que se quiere mostrar
//en este caso el enfasis
	switch (ptr_struct->Enfasis){
		case 1:
			printf("\nEnfasis: Electronica\n");
		break;
		case 2:
			printf("\nEnfasis: Redes\n");
		break;
		case 3:
			printf("\nEnfasis: Potencia\n");
		break;
		case 4:
			printf("\nEnfasis: Control\n");
		break;
		default:
			printf("\nEnfasis: Se ingresó un numero equivocado\n");
		
	}//fin del switch
}//fin del print
//en el main se llaman las funciones para su ejecucion
int main(){
	//se crea la varaible dato tipo array para decirle al puntero que inicie en la primer casilla de el struct
	struct datos_persona dato[SIZE];
	//el puntero tipo struct datos_persona para poder moverme entre las "casillas" del struct
	struct datos_persona *ptr_struct;
	ptr_struct=&dato[0];
	int selector;
	//se hace un for para que escriba los valores recibidos
	for(selector=0;selector<SIZE;selector++){
		set_struct(ptr_struct,selector);
		//al aumentar el valor del puntero se cambia el espacio del arreglo
		ptr_struct++;
	}
		
	//se vuelve a mandar el puntero a la posición inicial en el struct para imprimir desde el inicio
	ptr_struct=&dato[0];
	
	for(selector=0;selector<SIZE;selector++){
		print_struct(ptr_struct,selector);
		ptr_struct++;
	}
	return 0;
	
}//fin del main
