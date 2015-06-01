El codigo esta programado en el copilador Dev C++
En algunos otros compiladores es muy probable que marque error en las funciones
system("pause"); 
Lo cual puede ser sustituida por: getch();

system("cls");
Lo cual puede ser sustituido por:  clrscr();
---------------------------------------------------------------------------------
Technology Institute of
Ensenada
Students:
Sergio Antonio Cruz Olivares
Diana Marina Alonso Romero
M.I.
Alejandro Chávez Sánchez.
Subject:
Automata I
C Compiler
Date:
2015/May
INTRODUCTION.
To do a compiler project, the first step is select what type of compiler we
want to do. In this case, we choose a C Compiler programmed in C language. But,
¿Why we choose C? We choose C language because it easy in a way and it
supports structured programming, lexical variable scope and recursion. Next, we
will explain what conforms our compiler.
We use the next structs.
1.- Lexic struct.
struct milista
{
int renglon;
char dato[100];
int token;
struct milista *sig;
struct milista *ant;
};
typedef struct milista nodo;
typedef nodo *tipo;
tipo k=NULL;
2.- Variable struct.
struct typelista
{
int renglon;
char variableName[100];
char value[100];
int token;
int called;
struct typelista *sig;
struct typelista *ant;
};
typedef struct typelista typenodo;
typedef typenodo *typelist;
typelist types=NULL;
And we use this list of tokens.
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
// [99] DONT EXIST TOKEN
// 87 Variable name
// 88 String
// 89 String value (Token for variables names) All numerics value
// 90 Numeric Values (Token for variables names) int
// 91 Float numeric value (Token for variables names) float
// 92 double numeric value (Token for variables names) double
LEXIC.
We create the next functions to help us to build this compiler.
Function Strcatint: This function is used to attach strings with characters that is
received as number, this number is converted to character using ASCII Code.
char *strcatint (char *str, int x)
{
char z, a[2];
z = x;
a[0] = z;
a[1] = 0;
 strcat(str, a);
 return str;
}
Function varcmp: This function compare the given variable name with the rest of
declared variables before. If the variable name is already used the function will
return 0, else return 1.
int varcmp(char *var){
typelist s = types;
while(s){
if(strcmp(var, s->variableName) == 0){
return 0;
}
s = s->sig;
}
return 1;
}
Function vartype: If the variable is already called, this function tells what type is,
else return 0.
typelist s = types;
while(s){
if(strcmp(var, s->variableName) == 0){
return s->token;
}
s = s->sig;
}
return 0;
}
Function decvarcmp: This function help us to know if the variable is already
declared.
typelist s = types;
while(s){
if(strcmp(var, s->variableName) == 0){
s->called++;
if(s->called > 1)
return 0;
else
return 1;
}
s = s->sig;
}
return 1;
}
Function parea: This function receives a token and compares it with the actual
token. If both tokens are the same the function returns 1, else 0.
int parea(int ntoken){
if(ntoken==k->token)
return 1;
else
return 0;
}
int pareas (int ntoken){
if (ntoken==k->token){
k=k->sig;
return 1;
}else{
printf("Error en la linea [%d] cerca de %s\n", k->renglon, k->dato);
//if(k-> token!=111)
// printf("------ token= %d \n",k->token);
}
return 0;
}
Function error: This function receives string, cleans the screen, prints the string
and return 0.
int error(char *msj){ finaliza).
system("cls");
printf("Error en la linea %d cerca de '%s' \n%s\n", k->renglon, k->dato, msj);
return 0;
}
Function guardar: This function is divided in the next sections.
Symbols: this section separate the symbols and then save them individually.
Space: the spaces are removed.
Enter: count lines.
Numbers: Obtain the value.
Double quotes: saves quotes, then string.
Tab: tabs are removed.
Parenthesis: save parenthesis.
Reserved words: if exists, search and save, else shows token.
Variable: saves type, name and value.
Postfix Function.
To compare the addition, subtraction, multiplication and division, we will convert
the respective characters to string and then we will store them in an array. Then, as
we can see, in line 21 of the library funciones.h, when we called mathematical
expression, this will be followed by one of the symbols shown below:
+ - ( ) Numbers Function Var Logic OP.
If the mathematical expression doesn’t meet one of the above, the program will
throw an error.
Then we find a cycle, it will ended when it finds one of the following symbols.
; < > ) = & |
Then, we will use a label called start.
We will integrate an if in case the data of the current position is a variable or a
number. If it is a variable we will compare if it exists or it’s declared. Also we will
compares if it’s different to a string. In both cases, we will save it in salida pile.
If it is an arithmetic operator, a switch that verifies the data token is executed.
Case 13 (addition) and case 16 (subtraction): These will be accommodated in the
stack aux.
Case 20 (multiplication) and case 22 (division): If the aux stack is empty the data
entered on the stack automatically. Otherwise, we get the values from the stack 
aux and we put them to the output until a multiplication, division, a parenthesis
that opens aux or until the stack is empty. Finding a multiplication, division or "("
exits the cycle and advance to the label next otherwise the subs Variable will add
the last value of aux removing it from said stack. After the stack called output will
be integrated. It is clean the subs variable and the process repeats.
At the end of the cycle, we find the label next. Following the stack aux we put the
data we currently have.
Case 4 (opening parenthesis): gets directly to the auxiliary stack.
Case 5 (closing parenthesis): a cycle that will end until you find an opening
parenthesis. If the stack is empty aux we go to the label “ERR” (error). Otherwise
we clean the subs variable and assign the variable latest aux and incorporate the
output stack. If the far ends of the stack equals aux "(" then take it out and remove
the aux stack.
Switch´s end
If it is not an arithmetic operator (begin else) find and print the label “ERR” there
is an error in the current line fences current data. Then we go to the label “END”,
ending else.
It advances to the next item in the list.
If the data token is a closing parenthesis, we move one position and check whether
this new position equals an arithmetic operator; if true, it will back one position
and headed to the label start. Otherwise, we go back one position and the cycle
continues.
Ending the cycle of mathematical expression.
SYNTACTIC.
In this section we will verify if the user typed the code correctly. Else, the
compiler will throw an error or an approximate. In this case, we will need the next
functions:
 Parea: Verify if the following data is the correct.
 ExpMath: Make an expression.
 Error: Ends and show “error”.
 Varcmp: Verify if the variable is in the list.
 Decvrcmp: Verify if the variable was declared.
 Vartype: Returns variable type.
Variable declarations (CHAR - INT – FLOAT)
To make a variable declaration, we need to be sure the type of this. Then, a
procedure is performed to check the syntactic part.
Int: Verify that the name variable is declared only once and, if the values are
numbers. Can be declared in the next way:
 Int a;
 Int a=5;
 Int a=5, b;
Float: Verify that the name variable is declared only once and, if the values are
numbers, the same if it contains a decimal. Can be declared in the next way:
 Float a;
 Float a=5;
 Float a=4, b;
Char: Verify that the name variable is declared only once and the value just can be
a string just in case if it contains something. Can be declared in the next way.
 Char a;
 Char “hola”;
 Char “Hello”, b;
Assignments.
We can do reference to assignments to variable type int, char and float provided
that we they comply with the rules of correct grammars.
If a variable is out of the list or isn’t declared, the program will throw an error and
will end.
 Int
o a=ExpMath;
 float
o a=ExpMath;
 Char
o a=”String”;
Print function.
We can do a reference to print function and it must have the following format:
 printf
 prinft(“text”);
Logistic/conditional function.
To do a logistic function we will use: if, while, for.
 If: if function should have as parameters a mathematical expression, logical
operator and another mathematical expression.
 While: this function needs a mathematical expression, logical operator and
another mathematical expression in the parameter.
 for: Unlike other previous functions, this function may contain: (declaration;
condition; operation).
o You can assign values to variables previously declared.
o You can use the condition in this way: mathematical
expression, logical operator, mathematical expression.
o You can do an operation, it should have a variable
followed by a “=” followed by a mathematical expression.
(You can omit this step if you don’t need an operation). 
Automata.
Mathematical expression.
Declaration.
If.
type name ;
Assig. , name ;
name , name ;
if ( Math Exp Log. Op Math Exp
)
For.
Declaration.
Condition.
Operation.
While.
for ( variable = Asigg. ;
Math exp Log. Op Math exp ;
variable = Asigg. )
While ( Math exp Log. Op Math exp )
DECLARATION INT - FLOAT
¿It is a variable?
Label CHECKVAR
¿Variable exists?
|
| ¿Follow " ; "?
| | Program continues
| |________________________________
|
| ¿Follow " = "?
| | Using Mathematical Expression
| | ¿Follow " ; "?
| | | Program continues
| | |____________________________
| |
| | ¿Follow " ; "?
| | | Go to label CHECKVAR
| | |____________________________
| |
| | None of the above...
| | | ERROR
| | |____________________________
| |________________________________
|
| ¿Follow " ; "?
| | Go to label CHECKVAR
| |_____________________________
|
| None of the above...
| | ERROR
| |_____________________________
|
¿No? ERROR.

Do While
If
While
