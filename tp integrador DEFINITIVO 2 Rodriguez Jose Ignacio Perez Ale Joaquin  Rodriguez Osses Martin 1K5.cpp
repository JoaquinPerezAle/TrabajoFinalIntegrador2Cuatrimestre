#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
	Rodriguez Jose Ignacio 1k5
	Perez Ale Joaquin 1k5
	Rodriguez Osses Martin

*/



typedef char cadenanombre[10];
typedef char cadenacotra[33];
typedef char cadena[60];
typedef char cadenadetalles[381];


int Menu()
{
	int opcion = 0;
	
	printf("MENU");
	printf("\n----\n");
	printf("\n1- Modulo Espacio");
	printf("\n2- Modulo Del Recepcionista");
	printf("\n3- Modulo Administracion");

	printf("\n0- Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);
	
	return opcion;
}


int MenuEspacio()
{
	int opcion = 0;
	
	printf("MENU ESPACIOS");
	printf("\n-------------\n");
	printf("\n1- Iniciar Sesion");
	printf("\n2- Visulizar Lista de Espera de Turnos");
	printf("\n3- Registrar Evolucion del tratamiento");

	printf("\n4- Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);
	
	return opcion;
}
 
int MenuRecepcionista()
{
	int opcion = 0;
	
	printf("MENU RECEPCIONISTAS");
	printf("\n-------------------\n");
	printf("\n1- Iniciar Sesion");
	printf("\n2- Registrar Cliente");
	printf("\n3- Registrar Turno");
	printf("\n4- Listado de Atenciones por Profesional y Fecha");
	printf("\n5- Ver Turnos");

	printf("\n6- Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);
	
	return opcion;
}

int MenuAdministracion()
{
	int opcion = 0;
	
	printf("MENU ADMINISTRACION");
	printf("\n------------------------\n");
	printf("\n1- Registrar Profesional");
	printf("\n2- Registrar Usuario Recepcionista");
	printf("\n3- Atenciones por Profesional");
	printf("\n4- Ranking de Profesionales por Atenciones");

	printf("\n5- Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);
	
	return opcion;
}

struct fecha
{
	int dd;
	int mm;
	int aaaa;
	
};

struct registroUsuario
{
	cadenanombre User;
	cadenacotra Pass;
	cadena Nombre;
	int Tipo;
	
};

struct registroProfesionales
{
	cadena Nombre;
	int idProfesional;
	int DNI;
	int Telefono;
	int atenciones;
};

struct registroCliente
{
	cadena Nombre;
	cadena domicilio;
	int DNI;
	cadena Localidad;
	fecha FechaNacimiento;
	float Peso;
	int Telefono;
};

struct registroTurnos
{
	int idProfesional;
	fecha FechaTurno;
	int DNI;
	cadenadetalles detalleAtencion;
	int pendiente;
};



void carga(FILE *archiuser,int t)
{
	
	registroUsuario regi;
	int i;
	int largo;
	int mayus=0;
	int digitos=0;
	int bandera=0;
    cadenanombre nombre;
    
    
    cadenacotra contrasena;
	cadenacotra auxiliar;
	int b=0;
	int caracteres=0;
	int mayusculas=0;
	int minusculas=0;
	int numeros=0;
	int signos=0;
	int letras=0;
	int consec=0;
	int verificacion=0;
    
    cadena nombreyapellido;
    
    
	printf("Ingrese Nombre de usuario: ");
	 do
    {
	bandera=0;
    mayus=0;
    digitos=0;
    printf("\nIngrese el nombre del nuevo usuario: \n");
    _flushall();
    gets(nombre);
    largo=strlen(nombre);
    		
    		if(nombre[0]>=97&& nombre[0]<=122)//primera en minuscula
    		{
	    		 for(i=0;i<largo;i++)
			    {
			    	if(nombre[i]>64&& nombre[i]<91)
			    	{
			    		mayus++;//contar mayusculas
			    	}
			    	
			
			    }
	    	    if (mayus>=2)//por lo menos 2 mayusculas
			    {
			    	 for(i=0;i<largo;i++)
			    	 {
			    	 	if(nombre[i]>=48&& nombre[i]<=57)//contar digitos
			    	 	{
			    	 		digitos++;	
			    	 	}
			    	 }
			    	 if(digitos<=3)//maximo 3 digitos
			    	 {
			    	 	printf("\nEl nombre cumple con los requisitos\n ");
			    	 	bandera=1;
			    	 //	printf("%d",bandera);
			    	 }
			    	 else
			    	 {
			    	 	 printf("\nEl nombre debe maximo 3 digitos\n ");
			    	 }
			    }
			    else
			    {
			     printf("\nEl nombre debe tener por lo menos 2 mayusculas\n ");
			    }
    		}
    		
    		else
    		{
    			printf("\nEl nombre de usuario debe comenzar en minuscula \n");
    		}
		   
		    if (bandera==0)
		    {
		    	printf("\nIngrese el nombre nuevamente  \n");
		    }
		   // printf("%d",bandera);
			
			
	} while(bandera!=1);
	printf("\nEl nombre de usuario fue registrado \n\n\n");
	strcpy(regi.User,nombre);
  //  system("pause"); 
    
    


   	do
	{	
			printf("Ingrese contrasena: ");
			_flushall();
			gets(contrasena);
			caracteres=strlen(contrasena);
			
			  

        if((caracteres>5)&&(caracteres<33))
        {
        		for(int i=0;i<caracteres;i++)
				{
					if((contrasena[i]>32)&&(contrasena[i]<48))
						{
						signos++;
						}
					
						if((contrasena[i]>57)&&(contrasena[i]<65))
						{
						signos++;
						}
						if((contrasena[i]>90)&&(contrasena[i]<97))
						{
							signos++;
						}
						if((contrasena[i]>122)&&(contrasena[i]<=125))
						{
							signos++;
						}
				}
			if(signos==0)
			{
					
					for(int i=0;i<caracteres;i++)
					{
						if((contrasena[i]>64)&&(contrasena[i]<91))
						{
							mayusculas++;
						}
						if((contrasena[i]>96)&&(contrasena[i]<123))
						{
							minusculas++;
						}
						if((contrasena[i]>47)&&(contrasena[i]<58))
						{
							numeros++;
						}
					}
			
			
					if((mayusculas>0)&&(minusculas>0)&&(numeros>0))
					{
						digitos=0;
						verificacion=0;
						for(int i=0;i<caracteres;i++)
				    	 {
				    	 	if(contrasena[i]>=48&& contrasena[i]<=57)// pregunta por numeros seguidos
				    	 	{
				    	 		digitos++;
								if(digitos==3)
								{
									verificacion=1;
								}
				    	 	}
				    	 	if((contrasena[i]>=97&& contrasena[i]<=122)||(contrasena[i]>64 && contrasena[i]<91))// pregunta por letras seguidos
				    	 	{
				    	 		digitos=0;
								
				    	 	}
				    	}
				    	 	if (verificacion!=1) 
				    	 	{
				    	 	
				    	 		letras=0;
				    	 		consec=0;
				    	 		strcpy(auxiliar, contrasena);
				    	 		strlwr(auxiliar);
				    	 		for(int i=0;i<caracteres;i++)
				    	 		{
				    	 			if((contrasena[i]>64)&&(contrasena[i]<91)&&(contrasena[i]>96)&&(contrasena[i]<123))
				    	 			{
					    	 			if(auxiliar[i]==((auxiliar[i+1])-1))
					    	 			{
					    	 				consec++;	
					    	 			}
					    	 		}
				    	 		
				    	 		}
				    	 		if(consec==0)
				    	 		{
				    	 			printf("Contraseña ingresada correctamente\n");
				    	 			b=1;
				    	 		}
				    	 		else
				    	 		{
				    	 			printf("No debe tener caracteres alfanumericos consecutivos\n");
				    	 		}
				    	 		
				    	 	}
				    	 	else
				    	 	{
				    	 		printf("no debe tener 3 digitos consecutivos\n");
				    	 	}
				    	 
						
						
					
						
					}
					else
					{
						printf("\ndebe tener al menos 1 mayuscula 1 minuscula y 1 numero\n");
					}
			}
			else
			{
				printf("\nla contrasena no debe tener simbolos\n");
			}
			
		}
		else
		{
			printf("\nLa contrasena debe tener entre 6 y 32 caracteres");
		}
	}while(b!=1);
	printf("\nContraseña Ingresada correctamente: ");
	strcpy(regi.Pass,contrasena);

	printf("\nIngrese su nombre y apellido: ");
	_flushall();
	gets(regi.Nombre);
	
	if(t==0)regi.Tipo=0;
	if(t==1)regi.Tipo=1;
	
	
	fseek(archiuser, 0, SEEK_END);
	

	fwrite(&regi, sizeof(regi), 1, archiuser);
	
	printf("\n\nUsuario cargado correctamente...");
	
	
	
	rewind(archiuser);

	fread(&regi, sizeof(regi), 1, archiuser);

	while (!feof(archiuser))
	{
		printf("\n\nUsuario: ");
		puts(regi.User);
		printf("\nContrasena: ");
		puts(regi.Pass);
		printf("\nNombre: ");
		puts(regi.Nombre);
		printf("\nTipo De Cuenta: ");
		if(regi.Tipo==0)
		{
			printf("Recepcionista\n");
		}
		else
		{
			printf("Profesional\n");
		}
		
		
		fread(&regi, sizeof(regi), 1, archiuser);
		
	} 
	
}



void cargaprofesional(FILE *archi)
{
	registroProfesionales regi;
	printf("Carga de Datos del Profesional\n");
	printf("\nIngrese apellido y nombre: ");
	_flushall();
	gets(regi.Nombre);
	printf("\nIngrese idProfesional: ");
	scanf("%d",&regi.idProfesional);
	printf("\nIngrese DNI: ");
	scanf("%d",&regi.DNI);
	printf("\nIngrese telefono: ");
	scanf("%d",&regi.Telefono);
	regi.atenciones=0;
	fseek(archi, 0, SEEK_END);
	

	fwrite(&regi, sizeof(regi), 1, archi);
	
	printf("\n\nUsuario cargado correctamente...");
	
	system("cls");
	
	rewind(archi);

	fread(&regi, sizeof(regi), 1, archi);

	while (!feof(archi))
	{
		printf("\n\nApellido y nombre: ");
		puts(regi.Nombre);
		printf("\nID Profesional: %d ",regi.idProfesional);
		printf("\nDNI: %d",regi.DNI);
		printf("\nTelefono: %d",regi.Telefono);
		
		
		
		fread(&regi, sizeof(regi), 1, archi);
		
	} 
	
}

void LoginRecepcionista(FILE *archi,int &verif)
{
	registroUsuario regi;
	verif=0;
	cadena user;
	cadena contrasena;
	

	
	printf("Ingrese su Usuario: ");
	_flushall();
	gets(user);
	printf("Ingrese su Contrasena: ");
	_flushall();
	gets(contrasena);
	rewind(archi);

	fread(&regi, sizeof(regi), 1, archi);
	while (!feof(archi))
	{
		if(regi.Tipo==0)
		{
			if((strcmp(user,regi.User))==0)
			{
				if((strcmp(contrasena,regi.Pass))==0)
				{
					printf("Sesion Iniciada Correctamente ");
					verif=1;
					
				}
			}
			
		}
		
		fread(&regi, sizeof(regi), 1, archi);
	} 
		if(verif==0)
			{
				printf("\nNo se encontro el Usuario...");
			}
	
}



void cargaClientes(FILE *archi)
{
	registroCliente regi;
	printf("---Carga del Cliente---\n");
	printf("\nIngrese Apellido y nombre: ");
	_flushall();
	gets(regi.Nombre);
	printf("\nIngrese Domicilio: ");
	_flushall();
	gets(regi.domicilio);
	
	printf("\nIngrese DNI: ");
	scanf("%d",&regi.DNI);
	
	printf("\nIngrese Localidad: ");
	_flushall();
	gets(regi.Localidad);
	printf("\nIngrese Fecha de nacimiento: ");
	do
	{
		printf("\nDia: ");
		scanf("%d",&regi.FechaNacimiento.dd);
		if(regi.FechaNacimiento.dd>31)
		{
			printf("\nLos dias No pueden ser mayor a 31\n");
		}
	}while(regi.FechaNacimiento.dd>31);
	
	do
	{
	
		printf("\nMes: ");
		scanf("%d",&regi.FechaNacimiento.mm);
		if(regi.FechaNacimiento.mm>12)
		{
			printf("\nLos Meses no pueden ser mayor a 12");
		}
	}while(regi.FechaNacimiento.mm>12);
	printf("\nAnio: ");
	scanf("%d",&regi.FechaNacimiento.aaaa);
	
	printf("\nIngrese Peso: ");
	scanf("%f",&regi.Peso);
	printf("\nIngrese Telefono: ");
	scanf("%d",&regi.Telefono);
	
	fseek(archi, 0, SEEK_END);
	

	fwrite(&regi, sizeof(regi), 1, archi);
	printf("\nCliente Cargado Correctamente..");
	
	
	rewind(archi);

	fread(&regi, sizeof(regi), 1, archi);

	while (!feof(archi))
	{
		printf("\nNombre: ");
		puts(regi.Nombre);
		printf("\nDomicilio: ");
		puts(regi.domicilio);
		printf("\nDNI: %d",regi.DNI);
		printf("\nLocalidad: ");
		puts(regi.Localidad);
		printf("\nfecha de nacimiento: %d/%d/%d",regi.FechaNacimiento.dd,regi.FechaNacimiento.mm,regi.FechaNacimiento.aaaa);
		printf("\nPeso: %.2f",regi.Peso);
		printf("\ntelefono: %d",regi.Telefono);
		
		
	
	
		fread(&regi, sizeof(regi), 1, archi);
		
	} 
	
	
}


void cargaTurno(FILE *archiTurnos,FILE *archiUsuarios,FILE *archiProfesionales,FILE *archiClientes)
{
	registroCliente regiclientes;
	registroUsuario regiusuarios;
	registroProfesionales regiprofesionales;
	registroTurnos regiturnos;
	int comp=0;
	
	

	do
	{
		printf("Ingrese ID del profesional: ");
		scanf("%d",&regiturnos.idProfesional);
		
		rewind(archiProfesionales);
		fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		while (!feof(archiProfesionales))
		{
			if(regiprofesionales.idProfesional==regiturnos.idProfesional)
			{
				comp=1;
				break;
			}

			fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		} 
		if((feof(archiProfesionales))&&(comp==0))
		{
			printf("\nNo se encontro el ID Ingrese Nuevamente\n");
		}
		if(comp==1)
		{
			printf("\nID correcta\n");
		}
	}while(comp!=1);
	
	printf("\nIngrese Fecha del turno: ");
	do
	{

		printf("\nDia: ");
		scanf("%d",&regiturnos.FechaTurno.dd);
		if(regiturnos.FechaTurno.dd>31)
		{
			printf("\nLos dias No pueden ser mayor a 31\n");
		}
	}while(regiturnos.FechaTurno.dd>31);
	
	do
	{
		printf("\nMes: ");
		scanf("%d",&regiturnos.FechaTurno.mm);
		if(regiturnos.FechaTurno.mm>12)
		{
			printf("\nLos meses No pueden ser mayor a 12\n");
		}
	}while(regiturnos.FechaTurno.mm>12);
	
	printf("\nAnio: ");
	scanf("%d",&regiturnos.FechaTurno.aaaa);
	
	comp=0;
	do
	{
		printf("Ingrese DNI del Cliente: ");
		scanf("%d",&regiturnos.DNI);
		
		rewind(archiClientes);
		fread(&regiclientes, sizeof(regiclientes), 1, archiClientes);
		while (!feof(archiClientes))
		{
			if(regiclientes.DNI==regiturnos.DNI)
			{
				comp=1;
				break;
			}

			fread(&regiclientes, sizeof(regiclientes), 1, archiClientes);
		} 
		if((feof(archiClientes))&&(comp==0))
		{
			printf("\nNo se encontro el DNI Ingrese Nuevamente\n");
		}
		if(comp==1)
		{
			printf("\nDNI correcto");
		}
	}while(comp!=1);
	
	printf("\nIngrese los detalles de atencion: ");
	_flushall();
	gets(regiturnos.detalleAtencion);
	regiturnos.pendiente=0;
	
	fseek(archiTurnos, 0, SEEK_END);
	

	fwrite(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
	printf("\nTurno Cargado Correctamente..");
	
	
	
	rewind(archiTurnos);

	fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);

	while (!feof(archiTurnos))
	{
		printf("\n\nid del Profesional para el turno: %d ",regiturnos.idProfesional);
		printf("\nFecha del turno: %d/%d/%d",regiturnos.FechaTurno.dd,regiturnos.FechaTurno.mm,regiturnos.FechaTurno.aaaa);
		printf("\nDNI Cliente: %d",regiturnos.DNI);
		printf("\ndetalles de atencion: ");
		puts(regiturnos.detalleAtencion);
		printf("\n\n");
	
		fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
		
	} 
	
}



void Listadorecepcion(FILE *archiTurnos,FILE *archiProfesionales)
{
	registroProfesionales regiprofesionales;
	registroTurnos regiturnos;
	fecha regi;
	int comp=0;
	
	comp=0;
	do
	{
		printf("\nIngrese Fecha a Buscar: ");
		printf("\nDia: ");
		scanf("%d",&regi.dd);
		printf("\nMes: ");
		scanf("%d",&regi.mm);
		printf("\nAnio: ");
		scanf("%d",&regi.aaaa);
	
		rewind(archiTurnos);
		fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
		while (!feof(archiTurnos))
		{
			if(regiturnos.FechaTurno.dd==regi.dd)
			{
				if(regiturnos.FechaTurno.mm==regi.mm)
				{
					if(regiturnos.FechaTurno.aaaa==regi.aaaa)
					{
						
						
						comp=1;
						break;
					}
				}

			}

			fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
		} 
		if((feof(archiTurnos))&&(comp==0))
		{
			printf("\nNo se encontro un Turno en esa fecha. Ingrese nuevamente \n");
		}
		if(comp==1)
		{
			printf("\nTurno encontrado");
		}
	}while(comp!=1);
	

	do
	{	
		rewind(archiProfesionales);
		fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		while (!feof(archiProfesionales))
		{
			if(regiprofesionales.idProfesional==regiturnos.idProfesional)
			{
				printf("\n\nProfesional: ");
				puts(regiprofesionales.Nombre);
				printf("\nID: %d",regiprofesionales.idProfesional);
				printf("\nFecha del turno: %d/%d/%d\n\n",regi.dd,regi.mm,regi.aaaa);
				printf("\nDNI Cliente: %d",regiturnos.DNI);
						
						
				break;
				
				

			}

			fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		} 
		if((feof(archiProfesionales))&&(comp==0))
		{
			printf("\nNo se encontro un Turno en esa fecha. Ingrese nuevamente \n");
		}
		if(comp==1)
		{
			printf("\nTurno correcto");
		}
	}while(comp!=1);
}



void loginprofesional(FILE *archi,int &verif)
{
	registroUsuario regi;
	verif=0;
	cadena user;
	cadena contrasena;
	

	
	printf("Ingrese su Usuario: ");
	_flushall();
	gets(user);
	printf("Ingrese su Contrasena: ");
	_flushall();
	gets(contrasena);
	rewind(archi);

	fread(&regi, sizeof(regi), 1, archi);
	while (!feof(archi))
	{
		if(regi.Tipo==1)
		{
			if((strcmp(user,regi.User))==0)
			{
				if((strcmp(contrasena,regi.Pass))==0)
				{
					printf("Sesion Iniciada Correctamente ");
					verif=1;
					
				}
			}
			
		}
		
		fread(&regi, sizeof(regi), 1, archi);
	} 
		if(verif==0)
			{
				printf("\nNo se encontro el Usuario...");
			}
	
}

void listaparaprofesional(FILE *archi,FILE *archiClientes)
{
	registroTurnos regi;
	registroCliente regiclientes;
	rewind(archi);
	int edad=0;
	int comp=0;

	fread(&regi, sizeof(regi), 1, archi);
	while (!feof(archi))
	{
		if(regi.pendiente==0)
		{
			printf("\n\nid del Profesional para el turno: %d ",regi.idProfesional);
			printf("\nFecha del turno: %d/%d/%d",regi.FechaTurno.dd,regi.FechaTurno.mm,regi.FechaTurno.aaaa);
			printf("\nDNI Cliente: %d",regi.DNI);
			printf("\ndetalles de atencion: ");
			puts(regi.detalleAtencion);
		//	printf("\n\n");
		//	printf("\nDatos del Cliente: ");
			
			
			
			
			do
			{	
			rewind(archiClientes);
			fread(&regiclientes, sizeof(regiclientes), 1, archiClientes);
			while (!feof(archiClientes))
			{
				if(regiclientes.DNI==regi.DNI)
				{
					printf("\nNombre: ");
					puts(regiclientes.Nombre);
					printf("\nDomicilio: ");
					puts(regiclientes.domicilio);
					edad=2021-regiclientes.FechaNacimiento.aaaa;
					printf("\nEdad: %d\n\n",edad);
							
					comp=1;		
					break;
					
					
	
				}

			fread(&regiclientes, sizeof(regiclientes), 1, archiClientes);
			} 
		}while(comp!=1);
			
		}
		
		fread(&regi, sizeof(regi), 1, archi);
	} 
}



void registrarevolucion(FILE *archiTurnos,FILE *archiClientes, FILE *archiProfesionales)
{
	registroTurnos regiturnos;
	registroCliente regiclientes;
	registroProfesionales regiprofesionales;
	FILE *archiaux;
	registroTurnos regiaux;
	cadena nombrebuscar;
	int comp=0;
	int idprof=0;
	registroProfesionales regiprofaux;
	printf("Ingrese su ID: ");
	scanf("%d",&idprof);
	
	do
	{	
	
		rewind(archiProfesionales);
		fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		while (!feof(archiProfesionales))
		{
			if(idprof==regiprofesionales.idProfesional)
			{
				archiaux = fopen("Archivoaux.dat", "w+b");
				
				if (archiaux == NULL)
				{
						printf("Error. No se pudo crear el archivo");
						exit(1);
				}
				
				regiprofaux=regiprofesionales;
				
				regiprofaux.atenciones++;
				rewind(archiProfesionales);
	
				fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
				
				while (!feof(archiProfesionales))
				{
					if(regiprofesionales.idProfesional==idprof)
					{
						fwrite(&regiprofaux, sizeof(regiprofaux), 1, archiaux);
					}
					else
					{
						fwrite(&regiprofesionales, sizeof(regiprofesionales), 1, archiaux);
					}
					fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
				}
				
				fclose(archiProfesionales);
				fclose(archiaux);
	
				remove("Archivoprofesionales.dat");
				
				rename("Archivoaux.dat", "Archivoprofesionales.dat");
				
				
				archiProfesionales = fopen("Archivoprofesionales.dat", "r+b");
	
				if (archiProfesionales == NULL)
				{
					archiProfesionales = fopen("archiProfesionales.dat", "w+b");
					
					if (archiProfesionales == NULL)
					{
						printf("Error. No se pudo crear el archivo");
						exit(1);
					}
				}
				
				
			//	printf("22222");
				
				
					rewind(archiProfesionales);
					fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
					while (!feof(archiProfesionales))
					{
						if(idprof==regiprofesionales.idProfesional)
						{
						//	printf("11111");
							comp=1;
							break;
						}
				
				
					}while(comp!=1);
				
		

			}

			fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		} 
		if((feof(archiProfesionales))&&(comp==0))
		{
			printf("\nNo se la ID. Ingrese nuevamente \n");
		}
		if(comp==1)
		{
			printf("\nID correcto\n");
		}
	}while(comp!=1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	comp=0;
		
	
	
	
	
	
	archiaux = fopen("Archivoaux.dat", "w+b");
	
	if (archiaux == NULL)
	{
			printf("Error. No se pudo crear el archivo");
			exit(1);
	}
	

	do
	{
		printf("\nIngrese Nombre y Apellido del Cliente: ");
		_flushall();
		gets(nombrebuscar);
		
		rewind(archiClientes);
		fread(&regiclientes, sizeof(regiclientes), 1, archiClientes);
		while (!feof(archiClientes))
		{
			if((strcmp(nombrebuscar,regiclientes.Nombre))==0)
			{
				comp=1;
				break;
			}

			fread(&regiclientes, sizeof(regiclientes), 1, archiClientes);
		} 
		if((!feof(archiClientes))&&(comp==0))
		{
			printf("\nNo se encontro el Cliente Ingrese Nuevamente\n");
		}
		if(comp==1)
		{
			printf("\nCliente correcto");
		}
	}while(comp!=1);
	
	
	
	comp=0;
	do
	{

		rewind(archiTurnos);
		fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
		while (!feof(archiTurnos))
		{

			if(regiclientes.DNI==regiturnos.DNI)
			{
			//	comp=1;
			//	break;

				
				regiaux=regiturnos;
				
				printf("\nActualize los detalles de atencion: ");
				_flushall();
				gets(regiaux.detalleAtencion);
				regiaux.pendiente=1;
				
				
				rewind(archiTurnos);
	
				fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
				
				while (!feof(archiTurnos))
				{
					if(regiclientes.DNI==regiturnos.DNI)
					{
						fwrite(&regiaux, sizeof(regiaux), 1, archiaux);
					}
					else
					{
						fwrite(&regiturnos, sizeof(regiturnos), 1, archiaux);
					}
					fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
				}
				
				fclose(archiTurnos);
				fclose(archiaux);
	
				remove("Archivoturnos.dat");
				
				rename("Archivoaux.dat", "Archivoturnos.dat");
				
				
				archiTurnos = fopen("Archivoturnos.dat", "r+b");
	
				if (archiTurnos == NULL)
				{
					archiTurnos = fopen("Archivoturnos.dat", "w+b");
					
					if (archiTurnos == NULL)
					{
						printf("Error. No se pudo crear el archivo");
						exit(1);
					}
				}
				
				comp=1;
				
				
				
			}
			
			if(comp==0)
			{
			
			fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
			}
			if(comp==1)
			{
				break;
			}
			
			
		} 


	}while(comp!=1);
	
	
	
	rewind(archiTurnos);

	fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);

	while (!feof(archiTurnos))
	{
		printf("\n\nid del Profesional para el turno: %d ",regiturnos.idProfesional);
		printf("\nFecha del turno: %d/%d/%d",regiturnos.FechaTurno.dd,regiturnos.FechaTurno.mm,regiturnos.FechaTurno.aaaa);
		printf("\nDNI Cliente: %d",regiturnos.DNI);
		printf("\ndetalles de atencion: ");
		puts(regiturnos.detalleAtencion);
		printf("\n\n");
	
		fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
		
	} 
	
	
}




void verturnos(FILE *archiTurnos)
{
	registroTurnos regiturnos;
	
	rewind(archiTurnos);

	fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);

	while (!feof(archiTurnos))
	{
		printf("\n\nid del Profesional para el turno: %d ",regiturnos.idProfesional);
		printf("\nFecha del turno: %d/%d/%d",regiturnos.FechaTurno.dd,regiturnos.FechaTurno.mm,regiturnos.FechaTurno.aaaa);
		printf("\nDNI Cliente: %d",regiturnos.DNI);
		printf("\ndetalles de atencion: ");
		puts(regiturnos.detalleAtencion);
		printf("\nEstado");
		if(regiturnos.pendiente==0)
		{
			printf("\nPendiente");
		}
		if(regiturnos.pendiente==1)
		{
			printf("\nAtendido");
		}
		printf("\n\n");
	
		fread(&regiturnos, sizeof(regiturnos), 1, archiTurnos);
		
	} 
}



void atencionesprofesionales(FILE *archiProfesionales)
{
	registroProfesionales regiprofesionales;
	
	rewind(archiProfesionales);
		fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		while (!feof(archiProfesionales))
		{
			printf("\nNombre:");
			puts(regiprofesionales.Nombre);
			printf("\nId:%d",regiprofesionales.idProfesional);
			printf("\nAtendidos: %d\n\n",regiprofesionales.atenciones);

			fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		} 
}


void mayoratenciones(FILE *archiProfesionales)
{
	registroProfesionales regiprofesionales;
	int mayor=0;
	
	rewind(archiProfesionales);
		fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		while (!feof(archiProfesionales))
		{
			if(regiprofesionales.atenciones>mayor)
			{
				mayor=regiprofesionales.atenciones;
			}
			
			fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		} 
		
		printf("\nEl Profesional a recibir el bono es : ");
		rewind(archiProfesionales);
		fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		while (!feof(archiProfesionales))
		{
			if(regiprofesionales.atenciones==mayor)
			{
				printf("\nNombre:");
				puts(regiprofesionales.Nombre);
				printf("\nId:%d",regiprofesionales.idProfesional);
				printf("\nAtendidos: %d\n\n",regiprofesionales.atenciones);
			}
			
			fread(&regiprofesionales, sizeof(regiprofesionales), 1, archiProfesionales);
		} 
		
		
}


main()
{
	FILE *Usuarios;
	
	FILE *Profesionales;
	
	FILE *Cliente;
	
	FILE *Turnos;
	
	int opc=0;
	int tipoaccount=0;
	int recep=0;
	int conf=0;

	
	Usuarios = fopen("Archivousuarios.dat", "r+b");
	
	if (Usuarios == NULL)
	{
		Usuarios = fopen("Archivousuarios.dat", "w+b");
		
		if (Usuarios == NULL)
		{
			printf("Error. No se pudo crear el archivo");
			exit(1);
		}
	}
	
	
	
	
	Profesionales = fopen("Archivoprofesionales.dat", "r+b");
	
	if (Profesionales == NULL)
	{
		Profesionales = fopen("Archivoprofesionales.dat", "w+b");
		
		if (Profesionales == NULL)
		{
			printf("Error. No se pudo crear el archivo");
			exit(1);
		}
	}
	
	
	
	
	Cliente = fopen("Archivoclientes.dat", "r+b");
	
	if (Cliente == NULL)
	{
		Cliente = fopen("Archivoclientes.dat", "w+b");
		
		if (Cliente == NULL)
		{
			printf("Error. No se pudo crear el archivo");
			exit(1);
		}
	}
	
	
	
	Turnos = fopen("Archivoturnos.dat", "r+b");
	
	if (Turnos == NULL)
	{
		Turnos = fopen("Archivoturnos.dat", "w+b");
		
		if (Turnos == NULL)
		{
			printf("Error. No se pudo crear el archivo");
			exit(1);
		}
	}
	
	
	
	
		do 
	{
		system("cls");	
		opc = Menu();
		system("cls");	
		
		switch ( opc )
		{
			case 1: {
						do
						{
						system("cls");
						opc = MenuEspacio();
						system("cls");
						switch ( opc )
						{
							case 1:
							{
								printf("Iniciar Sesion\n");
								conf=0;
								loginprofesional(Usuarios,conf);
								
								break;
							}
							case 2:
							{
								printf("Visualizar Lista de Espera De Turnos(INFORME)\n");
								if(conf==1)
								{
										listaparaprofesional(Turnos,Cliente);
								}
								else
								{
									printf("debe iniciar sesion para poder acceder");
								}
								break;
							}
							case 3:
							{
								printf("Registrar Evolucion Del Tratamiento\n");
								//if(conf==1)
								//{
									registrarevolucion(Turnos,Cliente,Profesionales);
							//	}
							//	else
							//	{
							//		printf("debe iniciar sesion para poder acceder");
							//	}
								break;
							}
							case 4: 
							{
								printf("Cierre De la Aplicacion\n");
								conf=0;
								break;
							}
							default:
							 {
								printf("Error. Opcion incorrecta...\n");
								break;
							}
						}
						printf("\n\n");
						system("pause");
						}while (opc != 4);
						break;
					}
			case 2:
			{
					do
						{
						system("cls");
						opc = MenuRecepcionista();
						system("cls");
						switch ( opc )
						{
							case 1:
							{
								printf("Iniciar Sesion\n");
								recep=0;
							//	tipoaccount=0;
								LoginRecepcionista(Usuarios,recep);
								break;
							}
							case 2:
							{
								printf("Registrar cliente\n");
								if(recep==1)
								{
									cargaClientes(Cliente);
								}
								else
								{
									printf("\nDebe Inciciar Sesion Para Poder Acceder");
								}
								break;
							}
							case 3:
							{
								printf("Registrar Turno\n");
								if(recep==1)
								{
									cargaTurno(Turnos,Usuarios,Profesionales,Cliente);
								}
								else
								{
									printf("\nDebe Inciciar Sesion Para Poder Acceder");
								}
								break;
							}
							case 4:
							{
								printf("Listado de Atenciones por Profesional y Fecha\n");
								if(recep==1)
								{
									Listadorecepcion(Turnos,Profesionales);
								}
								else
								{
									printf("\nDebe Inciciar Sesion Para Poder Acceder");
								}
								break;
							}
							case 5: 
							{
									printf("\nVer Turnos");
									
									verturnos(Turnos);
									
									
								break;
							}
							case 6: 
							{
								printf("Cierre De la Aplicacion\n");
								recep=0;
								break;
							}
							default:
							 {
								printf("Error. Opcion incorrecta...\n");
								break;
							}
						}
						printf("\n\n");
						system("pause");
						}while (opc != 6);
				break;
			}
			case 3:
			{
					do
						{
						system("cls");
						opc = MenuAdministracion();
						system("cls");
						switch ( opc )
						{
							case 1:
							{
								printf("Registrar Profesional\n");
								tipoaccount=1;
								carga(Usuarios,tipoaccount);
								
								cargaprofesional(Profesionales);
								
								break;
							}
							case 2:
							{
								printf("Registrar Usuario Resepcionista\n");
								tipoaccount=0;
								carga(Usuarios,tipoaccount);
								break;
							}
							case 3:
							{
								printf("Atencion por Profesional\n");
								
								atencionesprofesionales(Profesionales);
								
								break;
							}
							case 4:
							{
								printf("Ranking de Profesionales por Atenciones\n");
								mayoratenciones(Profesionales);
								break;
							}
							case 5: 
							{
								printf("Cierre De la Aplicacion\n");
								
								break;
							}
							default:
							 {
								printf("Error. Opcion incorrecta...\n");
								break;
							}
						}
						printf("\n\n");
						system("pause");
						}while (opc != 5);
				break;
			}

			case 0: {
						printf("Fin del programa...");
						break;
					}

			default: {
						printf("Error. Opcion incorrecta...");
						break;
					}
			
		};
		
		printf("\n\n");
	//	system("pause");
	} while (opc != 0);
	

	
	
}
