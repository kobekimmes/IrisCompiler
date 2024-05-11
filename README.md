# Iris Compiler

This is a toy project I am working on to get a better understanding   
of what happens behind the scenes after you "press the play button"   
or compile your code.  

The Iris Compiler has 4 main components/steps in its standard procedure:   
    1. Lexing - tokenization according to special rules (lexical analysis)
    2. Parsing - generate an AST (abstract syntax tree) (syntactic analysis)
    3. Instruction Generation - interpret AST to be
       able to actually do something with it
    4. Execution - execute instructions on a virtual stack-based machine

Written in C with no extra-dependencies  

# Syntax  

The Iris language is designed to model C and be an introduction to programming for  
new developers! It also takes inspiration from weakly typed languages like Python and TypeScript.

**Single line comments**  

function f_name(type var1, type var2) -> return_type {  
    return ...  
}  

An example of this being used;

**This function returns the sum of two numbers**  
  
function sum(num a, num b) -> num {  
    num c = a + b;  
    return c;  
}  



