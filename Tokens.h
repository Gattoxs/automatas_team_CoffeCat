typedef struct {
  char carc[50];
  int token;
  }Asig_Tok;
  Asig_Tok atoken[]={
		{"{",0},
        {"}",1},
        {"[",2},
        {"]",3},
        {"(",4},
        {")",5},
		{"\\",6}, //
        {".",7},
		{":",8},
		{";",9},
		{",",10},
        {"\'",11},
		{"\"",12},
        {"+",13},
		{"++",14}, //
		{"+=",15}, //
		{"-",16},
		{"--",17}, //
		{"-=",18}, //
		{"->",19}, //
		{"*",20},
		{"*=",21}, //
		{"/",22},
		{"/=",23}, //
		{"%",24},
		{"%=",25}, //
		{"=",26},
		{"==",27}, //
		{"<",28},
		{"<=",29}, //
		{">",30},
		{">=",31}, //
        {"!",32},
		{"!=",33}, //
		{"|",34},
		{"||",35}, //
        {"&&",36}, //
		{"&",37},
		{"#",38},
		{"if",39},
		{"else",40},
		{"switch",41},
		{"case",42},
        {"break",43},
		{"do",44},
		{"while",45},
		{"for",46},
		{"define",47},
        {"include",48},
		{"return",49},
		{"default",50},
		
		{"char",51},
		{"int",52},
        {"float",53},
        {"double",54},
		{"const",55},
		{"long",56},
        {"void",57},
        {"struct",58},
		
		{"clrscr",59},
		{"printf",60},
		{"cprintf",61},
		{"textcolor",62},
		{"textbackground",63},
		{"flushall",64},
		{"scanf",65},
		{"getch",66},
		{"getche",67},
		{"pow",68},
		{"sin",69},
		{"cos",70},
        {"tan",71},
		{"sqrt",72},
		{"gotoxy",73},
		{"short",74},
		{"strcpy",75},
		{"main",86},
};
// [99] DONT EXIST TOKEN
// 87 Variable name
// 88 String
// 89 String value (Token for variables names) All numerics value
// 90 Numeric Values (Token for variables names) int
// 91 Float numeric value (Token for variables names) float
// 92 double numeric value (Token for variables names) double



void imprimirTokens(){
	int i;
	for(i=0;i < 76;i++){
		printf("{%s, %d}\n",atoken[i].carc, atoken[i].token);
	}
}

//____________________ Asignar token ____________________//

int AToken(char palabra[100]){
int x = 0;
	while(x < 77){
		//printf("\nPalabra: %s, palTOken: %s", palabra, atoken[x].carc); system("pause");
		if(strcmp(atoken[x].carc, palabra) == 0){
			return atoken[x].token;
		}
		x = x + 1;
	}
	return 87;
}	
