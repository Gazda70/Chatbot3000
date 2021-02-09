#include <string>
#include <regex>
#include "PorterStemmer.h"

#define TRUE 1
#define FALSE 0

void PorterStemmer::stem(std::string& tostem)
{
    if (!tostem.empty())
    {
        toStem = tostem;
        setparamVC();
        wordLen = toStem.size();
        wordBeg = 0;
        step1a();
        step1bfirst();
        step1bsecond();
        step1c();
        if (paramVC > 0)
        {
            step2();
            setparamVC();
            if (paramVC > 0)
            {
                step3();
                setparamVC();
            }
            if (paramVC > 1)
            {
                step4();
                setparamVC();
            }
        }
        step5a();
        setparamVC();
        step5b();
    }
    tostem = toStem;
}
void PorterStemmer::setparamVC()
{
    //kwestia y
    std::regex m0("[^aeiou]+|[aeiou]+|[^aeiou]+[aeiou]+");
    std::regex m1("[^aeiou]+[aeiou]+[^aeiou]+[aeiou]+|[aeiou]+[^aeiou]+|"
        "[aeiou]+[^aeiou]+[aeiou]+|[^aeiou]+[aeiou]+[^aeiou]+");
    std::regex m2("[^aeiou]+[aeiou]+[^aeiou]+[aeiou]+[^aeiou]+[aeiou]+|[aeiou]+[^aeiou]+[aeiou]+[^aeiou]+"
        "|[aeiou]+[aeiou]+[^aeiou]+[aeiou]+[^aeiou]+|[^aeiou]+[aeiou]+[^aeiou]+[aeiou]+[^aeiou]+");
    if (std::regex_match(toStem, m0))
    {
        paramVC = 0;
    }
    else if (std::regex_match(toStem, m1))
    {
        paramVC = 1;
    }
    else if (std::regex_match(toStem, m2))
    {
        paramVC = 2;
    }
    else
    {
        paramVC = 3;
    }
}
void PorterStemmer::step1a()
{
        std::regex sses(".*sses");
        std::regex ies(".*ies");
        std::regex s(".*s");
        std::regex ss(".*ss");
        if (std::regex_match(toStem, sses) || std::regex_match(toStem, ies))
            eraseLast(3);
        else if (std::regex_match(toStem, s) && !std::regex_match(toStem, ss))
            eraseLast(1);
}

void PorterStemmer::step1bfirst()
{
    std::regex eed(".+eed");
    std::regex ed1(".*[aeiou].*ed");
    std::regex ed2(".*[b-df-hj-np-t]y.*ed");
    std::regex ing1(".*[aeiou].*ing");
    std::regex ing2(".*[b-df-hj-np-t]y.*ing");
    if (std::regex_match(toStem, eed) && paramVC > 0)
    {
        eraseLast(1);
    }
    else if (std::regex_match(toStem, ed1) || std::regex_match(toStem, ed2))
    {
        eraseLast(2);
    }
    else if (std::regex_match(toStem, ing1) || std::regex_match(toStem, ing2))
    {
        eraseLast(3);
    }
}

void PorterStemmer::eraseLast(int toerase)
{
    if (wordLen > toerase)
    {
        toStem.erase(toStem.length() - toerase, toStem.length() - 1);
  }
}

void PorterStemmer::step1bsecond()
{
        std::regex at(".*at");
        std::regex bl(".*bl");
        std::regex iz(".*iz");
        std::regex dbLetter(".*aa|.*bb|.*cc|.*dd|.*ee|.*ff|.*gg|.*hh|.*ii|.*jj|.*kk|.*mm|.*nn|.*oo|.*pp|.*qq|.*rr|.*tt|.*uu|.*vv|.*ww|.*xx|.*yy");
        std::regex cvc(".[^aeiou][aeiouy][^aeiouwxy]");
        if (std::regex_match(toStem, at) || std::regex_match(toStem, bl)
            || std::regex_match(toStem, iz) || (std::regex_match(toStem, cvc) && paramVC == 1))
        {
            toStem += 'e';
        }
        else if (std::regex_match(toStem, dbLetter))
        {
            toStem.erase(toStem.length() - 1);
        }
}


/* step1c() przekszta³ca koñcowe y w i kiedy w tekœciej jest kolejna samog³oska */
void PorterStemmer::step1c()
{
    std::regex bigY1(".*a|e|i|o|u.*y");
    std::regex bigY2(".*[b-df-hj-np-t]y.*y");
    if(std::regex_match(toStem, bigY1) || std::regex_match(toStem, bigY2))
        toStem[toStem.length() - 1] = 'i';
}

/* step2() mapuje podwójne koñcówki do pojedynczych*/
void PorterStemmer::step2()
{
    std::regex ational(".+ational");
    std::regex tional(".+tional");
    std::regex enci(".+enci");
    std::regex anci(".+anci");
    std::regex izer(".+izer");
    std::regex abli(".+abli");
    std::regex alli(".+alli");
    std::regex entli(".+entli");
    std::regex eli(".+eli");
    std::regex ousli(".+ousli");
    std::regex ization(".+ization");
    std::regex ation(".+ation");
    std::regex ator(".+ator");
    std::regex alism(".+alism");
    std::regex iveness(".+iveness");
    std::regex fulness(".+fulness");
    std::regex ousness(".+ousness");
    std::regex aliti(".+aliti");
    std::regex iviti(".+iviti");
    std::regex biliti(".+iviti");
    if (std::regex_match(toStem, ational) || std::regex_match(toStem, ization))
    {
        eraseLast(5);
        toStem += 'e';
    }
    else if(std::regex_match(toStem, tional) || std::regex_match(toStem, alli)|| std::regex_match(toStem, entli)
        || std::regex_match(toStem, eli)|| std::regex_match(toStem, ousli))
    {
        eraseLast(2);
    }
    else if (std::regex_match(toStem, enci)|| std::regex_match(toStem, anci)|| std::regex_match(toStem, abli))
    {
        toStem[wordLen-1] = 'e';
    }
    else if (std::regex_match(toStem, izer))
    {
        eraseLast(1);
    }
    else if (std::regex_match(toStem, ation) || std::regex_match(toStem, iviti))
    {
        eraseLast(3);
        toStem += 'e';
    }
    else if (std::regex_match(toStem, ator))
    {
        eraseLast(2);
        toStem += 'e';
    }
    else if (std::regex_match(toStem, alism)|| std::regex_match(toStem, aliti))
    {
        eraseLast(3);
    }
    else if (std::regex_match(toStem, iveness)|| std::regex_match(toStem, fulness)|| std::regex_match(toStem, ousness))
    {
        eraseLast(4);
    }
    else if (std::regex_match(toStem, biliti))
    {
        eraseLast(5);
        toStem += "le";
    }
}

/* step3() usuwa koñcówki -ic-, -full, -ness */
void PorterStemmer::step3()
{
    std::regex icate(".+icate");
    std::regex ative(".+ative");
    std::regex alize(".+alize");
    std::regex iciti(".+iciti");
    std::regex ical(".+ical");
    std::regex ful(".+ful");
    std::regex ness(".+ness");
    if (std::regex_match(toStem, icate)|| std::regex_match(toStem, alize)
        || std::regex_match(toStem, iciti)|| std::regex_match(toStem, ful))
    {
        eraseLast(3);
    }
    else if(std::regex_match(toStem, ative))
    {
        eraseLast(5);
    }
    else if (std::regex_match(toStem, ical))
    {
        eraseLast(2);
    }
    else if (std::regex_match(toStem, ness))
    {
        eraseLast(4);
    }
}

/* step4() usuwa koñcówki -ant, -ence itd., przy konstrukcji s³owa <c>vcvc<v>. */
void PorterStemmer::step4()
{
    std::regex al(".{2,}al");
    std::regex ance(".{2,}ance");
    std::regex ence(".{2,}ence");
    std::regex er(".{2,}er");
    std::regex ic(".{2,}ic");
    std::regex able(".{2,}able");
    std::regex ible(".{2,}ible");
    std::regex ant(".{2,}ant");
    std::regex ement(".{2,}ement");
    std::regex ment(".{2,}ment");
    std::regex ent(".{2,}ization");
    std::regex stion(".{2,}s|tion");
    std::regex ou(".{2,}ou");
    std::regex ism(".{2,}ism");
    std::regex ate(".{2,}ate");
    std::regex iti(".{2,}iti");
    std::regex ous(".{2,}ous");
    std::regex ive(".{2,}aliti");
    std::regex ize(".{2,}iviti");

    if (std::regex_match(toStem, al) || std::regex_match(toStem, er) 
        || std::regex_match(toStem, ic) || std::regex_match(toStem, ou))
    {
        eraseLast(2);
    }
    else if (std::regex_match(toStem, ant) || std::regex_match(toStem, ent)
        || std::regex_match(toStem, ism) || std::regex_match(toStem, ate)
        || std::regex_match(toStem, iti) || std::regex_match(toStem, ous)
        || std::regex_match(toStem, ive) || std::regex_match(toStem, ize))
    {
        eraseLast(3);
    }
    else if (std::regex_match(toStem, ance) || std::regex_match(toStem, ence)
        || std::regex_match(toStem, able) || std::regex_match(toStem, ible)
        || std::regex_match(toStem, ment) || std::regex_match(toStem, stion))
    {
        eraseLast(4);
    }
    else if (std::regex_match(toStem, ement))
    {
        eraseLast(5);
    }
}

/* step5() kroki koñcowe */
void PorterStemmer::step5a()
{
    std::regex e(".*e");
    std::regex cvce(".[^aeiou][aeiouy][^aeiouwxy]e");
    if (paramVC > 1 && std::regex_match(toStem, e) || paramVC == 1 && std::regex_match(toStem, cvce))
    {
        eraseLast(1);
    }
}

void PorterStemmer::step5b()
{
    std::regex dL(".*ll");
    if (paramVC > 1 && std::regex_match(toStem, dL))
    {
        eraseLast(1);
    }
}

