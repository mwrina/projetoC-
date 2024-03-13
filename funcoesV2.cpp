//Fun��es GERAIS

void limparArea(int colIni, int linIni, int colFin, int linFin)
{
	for (int x=colIni; x<=colFin; x++)
	{
		for (int y=linIni; y<=linFin; y++)
		{
			gotoxy(x,y); cout << " ";
		}
	}
}

void desenharMoldura(int colIni, int linIni, int colFin, int linFin)
{
	// limpa a �rea da moldura
	limparArea(colIni, linIni, colFin, linFin);
	
	// desenha as linhas horizontais
	for(int x=colIni; x<=colFin; x++)
	{
		gotoxy(x,linIni); 
		cout << "-";
		gotoxy(x,linFin); 
		cout << "-";
		
	}
	
	// desenha as linhas verticais
	for(int y=linIni; y<=linFin; y++)
	{
		gotoxy(colIni,y);
		cout << "|";
		gotoxy(colFin,y);
		cout << "|";
	}
	
	// arruma os cantos
	gotoxy(colIni,linIni); cout << "+";
	gotoxy(colFin,linIni); cout << "+";
	gotoxy(colIni,linFin); cout << "+";
	gotoxy(colFin,linFin); cout << "+";
}



void centralizar(string msg, int lin, int colIni, int colFin)
{
	int meio;
	meio = (colFin-colIni-msg.length())/2;
	gotoxy(meio,lin);
	cout << msg;
}

string mostrarMenu(int col, int lin, vector<string> opcoes)
{
	string op;
	int x;
	int colFin = col + opcoes[0].size() + 1;
	int linFin = lin + opcoes.size() + 3;
	
	desenharMoldura(col, lin, colFin, linFin);
	centralizar("Menu Principal", lin+1, col, colFin);
	col ++;
	lin += 2;
	
	for (x=0; x<opcoes.size(); x++)
	{
		gotoxy(col, lin+x); cout << opcoes[x];
	}
	
	gotoxy(col, lin+x);
	cout << "Opcao : ";
	op = getche();
	
	return op;
}

//-----------------------------------------------------------------
//Structs e Vetores

struct CANDIDATO
{
	int numCandidato;
	string nomeCandidato;
	int numPartido;
	int quantVotos;
};

struct ELEITOR
{
	int cpf;
	int zonaEleitoral;
};

vector<CANDIDATO> candidatos;
vector<ELEITOR> eleitores;

int n;
string conf;

//-----------------------------------------------------------------
//Fun��es do SISTEMA

void cadastrarCandidato()
{
		CANDIDATO cand;
					
		desenharMoldura(10,5,70,11);
		centralizar("Cadastro de candidatos",6,10,70);
		gotoxy(11,7); cout << "N�mero do Candidato : ";
		gotoxy(11,8); cout << "Nome do Candidato   : ";
		gotoxy(11,9); cout << "N�mero do Partido   : ";	

		gotoxy(33,7); cin >> cand.numCandidato;		
		fflush(stdin);
		gotoxy(33,8); getline(cin, cand.nomeCandidato);
		gotoxy(33,9); cin >> cand.numPartido;		
		cand.quantVotos = 0;

		fflush(stdin);
		candidatos.push_back(cand);
}

void listarCandidatos(int x, int y)
{
	gotoxy(x,y);
	cout << "Os candidatos registrados s�o:" << endl;

	gotoxy(x, y+2);     cout << "N�mero do Registro";
	gotoxy(x+20, y+2);  cout << "N�mero do Candidato";
    gotoxy(x+40, y+2);  cout << "N�mero do Partido";
    gotoxy(x+60, y+2); cout << "Nome do Candidato";
    
    int y2 = y+3;
    
	for(int i=0; i < candidatos.size(); i++)
	{
		gotoxy(x, y2+i);    cout << i+1;
		gotoxy(x+20, y2+i); cout << candidatos[i].numCandidato;
		gotoxy(x+40, y2+i); cout << candidatos[i].numPartido;
        gotoxy(x+60, y2+i); cout << candidatos[i].nomeCandidato;
	} 
}

void excluirCandidato()
{
	
	desenharMoldura(10,5,90,25);
	centralizar("Exclus�o de Candidato",6,10,90);
	
	listarCandidatos(11,8);
	
	int y = candidatos.size()+2;
	
	gotoxy(11,y+10); cout << "Informe o n�mero do registro do candidato que voc� deseja excluir.";
	gotoxy(11,y+11); cin >> n;
	
	n--;
	
	if(n>=0 && n<candidatos.size())
	{
		gotoxy(11,y+13); cout << "Voc� tem certeza que deseja deletar o registro " << n+1 << "? (S/N)";
		gotoxy(67,y+13); cin >> conf;

		if(conf == "S" || conf == "s")
		{
			candidatos.erase(candidatos.begin()+n);
			
			gotoxy(11,y+14); cout << "Pronto! Candidato deletado.";
		}
		
		else if(conf == "N" || conf == "n")
		{
			gotoxy(11,y+14); cout << "Certo. Voc� retornar� � p�gina inicial agora.";
		}
		
		else
		{
			gotoxy(11,y+14); cout << "O(s) caractere(s) digitado(s) n�o corresponde(m) a nenhuma das op��es dadas (S/N).";
			gotoxy(11,y+15); cout << "Aperte qualquer tecla para voltar � p�gina inicial.";
			getch();
		}
	}
	else
	{
		gotoxy(11, y+13); cout << "O registro informado n�o foi encontrado. Aperte qualquer tecla para voltar ao menu.";
		getch();
	}
	
	fflush(stdin);
}

void alterarCandidato()
{
	CANDIDATO c;

	desenharMoldura(10,5,100,25);
	centralizar("Edi��o de Candidato",6,10,100);
	
	listarCandidatos(11,8);
	
	int y = candidatos.size()+2;
	
	gotoxy(11,y+9);
	cout << "Informe o n�mero do registro do candidato que voc� deseja alterar: ";
	cin >> n;
	
	n--;
	
	if(n >= 0 && n < candidatos.size())
	{
		gotoxy(11,y+9); cout << "Digite as novas informa��es do candidato.                              "; 
		
		gotoxy(11,y+11); cout << "Registro " << n+1;
		gotoxy(11,y+12); cout << "N�mero do Candidato: ";
		gotoxy(11,y+13); cout << "Nome do Candidato:   ";
		gotoxy(11,y+14); cout << "N�mero do Partido:  ";
		fflush(stdin);
		
		gotoxy(33,y+12); 
		cin >> c.numCandidato;
		
		gotoxy(33,y+13);
		fflush(stdin);
		getline(cin, c.nomeCandidato);
		
		gotoxy(33,y+14);
		cin >> c.numPartido;
		
		gotoxy(11,y+15);
		cout << "Confirmar altera��o (S/N): ";
		fflush(stdin);
		getline(cin, conf);
		
		if (conf == "S" || conf == "s")
		{
			candidatos[n] = c;
			gotoxy(11,y+15);
			cout << "Prontinho. Voc� ser� redirecionado ao menu principal agora.";
		}
		else
		{
			gotoxy(11,y+15); cout << "Certo. Aperte qualquer tecla para voltar � tela inicial.";
			getch();
		}
	}
	else
	{
		gotoxy(11,y+10); cout << "Registro n�o encontrado. Aperte qualquer tecla para voltar � tela inicial.";
		getch();
	}
	
	
}

void cadastrarVoto(){
	
	int numCand, pos;
	bool achei = false;

	listarCandidatos(11,10);
	
	int y = candidatos.size()+2;
	
	gotoxy(11, y+12); 
	cout << "Informe o n�mero que representa o candidato em quem voc� deseja votar: ";
	cin >> numCand;
	
	for(int i=0; i<candidatos.size(); i++)
	{
		if(numCand == candidatos[i].numCandidato)
		{
			achei = true;
			pos = i;
			break;
		}
	}
	
	if(achei = true){
		candidatos[pos].quantVotos++;
	}
	
}

void cadastrarEleitor()
{
	CANDIDATO c;	
		
	desenharMoldura(10,5,90,20);
	centralizar("Vota��o",6,10,90);
			
	int cpfInf;
	int zonaEleInf;
	bool existe = false;
	ELEITOR eleitor;
	
	gotoxy(11,7); cout << "Informe seu CPF (somente n�meros): ";
	cin >> cpfInf;
	fflush(stdin);

	//VERIFICA se o CPF j� existe no sistema
	for(int i=0; i<eleitores.size(); i++)
	{
		if(cpfInf == eleitores[i].cpf) 
		{
			existe = true;
			break;
		}	
	}

	if(existe) //Se sim, N�O PODE votar
	{
		gotoxy(11,8); cout << "Seu CPF j� possui registro em nosso sistema. Voc� s� pode votar uma vez.";
		gotoxy(11,9); cout << "Aperte qualquer tecla para voltar ao menu principal.";
		getch();
	} 
	else //Se ainda n�o, PODE votar
	{				
		gotoxy(11,8); cout << "Informe sua zona eleitoral: ";
		cin >> eleitor.zonaEleitoral;
		eleitor.cpf = cpfInf;
		
		eleitores.push_back(eleitor);
		
		cadastrarVoto();

	}
	
	fflush(stdin);	
	
}

void mostrarResultados()
{
	
	desenharMoldura(10,5,100,25);
	centralizar("Resultados da Vota��o",6,10,100);
	
	gotoxy(11, 8);  cout << "N�mero do Candidato";
	gotoxy(35, 8);  cout << "N�mero do Partido";
    gotoxy(55, 8);  cout << "Nome do Candidato";
    gotoxy(75, 8);  cout << "Quantidade de Votos"; 

	for(int i=0; i < candidatos.size(); i++)
	{
		gotoxy(11, 9+i); cout << candidatos[i].numCandidato;
	    gotoxy(35, 9+i); cout << candidatos[i].numPartido;
	    gotoxy(55, 9+i); cout << candidatos[i].nomeCandidato;
	    gotoxy(75, 9+i); cout << candidatos[i].quantVotos;
	}
}
