#include "lex.h"
#include <map>


using namespace std;

string stringToUpper(string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

static map <Token, string> tokenPrint = {
        {PRINT,"PRINT"},
        {IF,"IF"},
        {BEGIN,"BEGIN"},
        {END,"END"},
        {IDENT,"IDENT"},
        {ICONST,"ICONST"},
        {SCONST,"SCONST"},
        {RCONST,"RCONST"},
        {PLUS,"PLUS"},
        {MINUS,"MINUS"},
        {MULT,"MULT"},
        {DIV,"DIV"},
        {EQ,"EQ"},
        {LPAREN,"LPAREN"},
        {RPAREN,"RPAREN"},
        {SCOMA,"SCOMA"},
        {COMA,"COMA"},
        {ERR, "ERR"},
        {DONE,"DONE"}
};

inline ostream& operator <<(ostream& out, const LexItem& tok){

    Token tt = tok.GetToken();
    out<<tokenPrint[tt];
    if(tt== IDENT|| tt==ICONST || tt==SCONST || tt== ERR||tt== RCONST){
        out<< " (" << tok.GetLexeme() <<")";

    }
    out<<" Line # : "<<tok.GetLinenum()<<endl;

    return out;
}
