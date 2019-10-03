#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define PURGAR fflush(stdin);


int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 float minimo,
			 float maximo,
			 int reintentos)
{
	int retorno = EXIT_ERROR;
	float buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			PURGAR
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getChar(  char *pResultado,
			  char *pMensaje,
			  char *pMensajeError,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%c",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getString (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[500];
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			PURGAR
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
