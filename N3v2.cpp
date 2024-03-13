#include <iostream>
#include <vector>
#include <conio2.h>
#include <string>
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

#include "funcoesV2.cpp"

int main(){
			
	setlocale(LC_ALL, "portuguese");
				
	int sen = 12345;
	int sen1;
	string resp;	
	
	string op;
	int posicao;
	
	vector<string> menuPrincipal;
	menuPrincipal.push_back("1. Cadastrar candidato      ");
	menuPrincipal.push_back("2. Alterar/Excluir candidato");
	menuPrincipal.push_back("3. Votar                    ");
	menuPrincipal.push_back("4. Mostrar resultados       ");
	menuPrincipal.push_back("0. Sair                     ");
	
	while(true)
	{		
		clrscr();
		desenharMoldura(1, 1, 100, 30);
		centralizar("Sistema Eleitoral", 2, 1, 80);	
		op = mostrarMenu(2, 3, menuPrincipal);
		
		if(op == "0") break;
		
		if(op == "1")
		{
			//CADASTRAR candidato
			
			gotoxy(2,12);
			cout << "Digite a senha para comprovar que você é administrador: ";
			cin >> sen1;
			
			if(sen1 == sen) //senha CORRETA
			{
				
				cadastrarCandidato();
				
			}
			else //senha INCORRETA
			{
				
				cout << "Senha incorreta! Aperte qualquer tecla para voltar ao menu principal.";
				getch();
				
			}
		}
		
		//EXCLUIR ou ALTERAR registro de candidato
		else if(op == "2")
		{
			CANDIDATO c;
			
			gotoxy(2,12);
			cout << "Digite a senha para comprovar que você é administrador: ";
			cin >> sen1;
			
			if(sen1 == sen) //senha CORRETA
			{
				gotoxy(2,14);
				cout << "Você deseja excluir ou alterar os dados do candidato? (E para excluir/A para alterar/V para voltar) \n";
				gotoxy(2, 15); cin >> resp;
				
				//EXCLUIR candidato
				if(resp == "E" || resp == "e")
				{
					excluirCandidato();
				}
				
				//ALTERAR candidato
				else if(resp == "A" || resp == "a")
				{
					alterarCandidato();
				}
				
				//VOLTAR
				else if(resp == "V" || resp == "v")
				{
					gotoxy(2,17); cout << "Aperte qualquer tecla e você retornará ao menu principal.";
					getch();
				}
				
				//N/A
				else
				{
					cout << "Você não digitou nenhuma das opções válidas. Por favor, aperte qualquer tecla para voltar ao menu principal.";
					getch();
				}
			}
			else //SENHA INCORRETA
			{
				cout << "Senha incorreta! Aperte qualquer tecla para voltar ao menu principal.";
				getch();	
			}
		}
		
		//cadastrar VOTO e ELEITOR
		else if(op == "3")
		{
			cadastrarEleitor();
		}		
		
		//MOSTRAR RESULTADOS
		else if(op == "4")
		{
			gotoxy(2,12);
			cout << "Digite a senha para comprovar que você é administrador: ";
			cin >> sen1;
			
			if(sen1 == sen) //senha CORRETA
			{
				mostrarResultados();
				getch();
			}
			else
			{
				cout << "Senha incorreta! Aperte qualquer tecla para voltar ao menu principal.";
				getch();
			}
				
		}			
		
	}
	
	return 0;
}


