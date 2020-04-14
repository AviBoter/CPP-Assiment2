#include "FamilyTree.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TEST_CASE("Noraml Tree"){
	family::Tree T ("Yosef"); // Yosef is The "rooT" of The Tree (The youngesT person).
	T.addFather("Yosef", "Yaakov")   // Tells The Tree ThaT The faTher of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells The Tree ThaT The moTher of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");

	
     CHECK( T.relation("Yaakov").compare("father")==0);
     CHECK( T.relation("Rachel").compare("mother")==0);
     CHECK( T.relation("Rivka").compare("grandmother")==0);
     CHECK( T.relation("Avraham").compare("great-grandfather")==0);
     CHECK( T.relation("Terah").compare("great-great-grandfather")==0);
     CHECK( T.relation("xyz").compare("unrelated")==0);
     CHECK( T.relation("Yosef").compare("me")==0);
     CHECK(T.relation("Yaakov").compare("x")==-1);
     CHECK(T.relation("Rachel").compare("x")==-1);
     CHECK(T.relation("Rivka").compare("x")==-1);
     CHECK(T.relation("Avraham").compare("x")==-1);
     CHECK(T.relation("Yosef").compare("x")==-1);
     CHECK(T.relation("Isaac").compare("x")==-1);
     CHECK(T.relation("Yaakov").compare("yy")==-1);
     CHECK(T.relation("Rivka").compare("yy")==-1);
     CHECK(T.relation("Avraham").compare("yy")==-1);
     CHECK(T.relation("Terah").compare("yy")==-1);
     CHECK(T.relation("xyz").compare("yy")==-1);
     CHECK(T.relation("Yaakov").compare("yes")==-1);
     CHECK(T.relation("Yaakov").compare("q")==-1);
     CHECK(T.relation("Yaakov").compare("w")==-1);
     CHECK(T.relation("Yaakov").compare("e")==-1);
     CHECK(T.relation("Yaakov").compare("r")==-1);
     CHECK(T.relation("Yaakov").compare("T")==-1);
     CHECK(T.relation("Yaakov").compare("y")==-1);
     CHECK(T.relation("Yaakov").compare("u")==-1);
     CHECK(T.relation("Yaakov").compare("i")==-1);
     CHECK(T.relation("Yaakov").compare("o")==-1);
     CHECK(T.relation("Yaakov").compare("p")==-1);
     CHECK(T.relation("Yaakov").compare("a")==-1);
     CHECK(T.relation("Yaakov").compare("s")==-1);
     CHECK(T.relation("Yaakov").compare("d")==-1);
     CHECK(T.relation("Yaakov").compare("f")==-1);
     CHECK(T.relation("Yaakov").compare("g")==-1);
     CHECK(T.relation("Yaakov").compare("h")==-1);
     CHECK(T.relation("Yaakov").compare("j")==-1);
     CHECK(T.relation("Yaakov").compare("k")==-1);
     CHECK(T.relation("Yaakov").compare("l")==-1);
     CHECK(T.relation("Yaakov").compare("z")==-1);
     CHECK(T.relation("Yaakov").compare("v")==-1);
     CHECK(T.relation("Yaakov").compare("b")==-1);
     CHECK(T.relation("Yaakov").compare("n")==-1);
     CHECK(T.relation("Yaakov").compare("m")==-1);
     CHECK(T.relation("Yaakov").compare("xc")==-1);
     CHECK(T.relation("Yaakov").compare("c")==-1);
     CHECK(T.relation("Rivka").compare("q")==-1);
     CHECK(T.relation("Rivka").compare("w")==-1);
     CHECK(T.relation("Rivka").compare("e")==-1);
     T.remove("Yaakov");
     CHECK(T.relation("Rivka").compare("r")==-1);
     CHECK(T.relation("Rivka").compare("Tx")==-1);
     CHECK(T.relation("Rivka").compare("y")==-1);
     CHECK(T.relation("Rivka").compare("u")==-1);
     CHECK(T.relation("Rivka").compare("ii")==-1);
     CHECK(T.relation("Rivka").compare("f")==-1);
     CHECK(T.relation("Rivka").compare("g")==-1);
     CHECK(T.relation("Rivka").compare("h")==-1);
     CHECK(T.relation("Rivka").compare("j")==-1);
     CHECK(T.relation("Rivka").compare("k")==-1);
     CHECK(T.relation("Rivka").compare("mm")==-1);
     CHECK(T.relation("Rivka").compare("n")==-1);
     CHECK(T.relation("Rivka").compare("b")==-1);
     CHECK(T.relation("Rivka").compare("v")==-1);
     CHECK(T.relation("Rivka").compare("c")==-1);
     CHECK(T.relation("Rivka").compare("ccc")==-1);
     CHECK(T.relation("Rivka").compare("ds")==-1);
     CHECK(T.relation("Rivka").compare("fg")==-1);
     CHECK(T.relation("Rivka").compare("ghh")==-1);
     CHECK(T.relation("Rivka").compare("kj")==-1);
     CHECK(T.relation("Rivka").compare("bv")==-1);
     CHECK(T.relation("Rivka").compare("yT")==-1);
     CHECK(T.relation("Rivka").compare("yTy")==-1);
     CHECK(T.relation("Rivka").compare("uov")==-1);
     CHECK(T.relation("Rivka").compare("pp")==-1);
     CHECK(T.relation("Rivka").compare("lll")==-1);
    
     
    
    CHECK(T.find("mother").compare("Rachel")==0);
    CHECK(T.find("great-great-grandfather").compare("Terah")==0);
    CHECK(T.find("greaT-grandfaTher").compare("Avraham")==0);
    CHECK(T.find("grandmoTher").compare("Rivka")==0);
    CHECK(T.find("q").compare("Yaakov")==0);
    CHECK(T.find("w").compare("mother")==1);
    CHECK(T.find("e").compare("mother")==1);
     CHECK(T.find("r").compare("mother")==1);
     CHECK(T.find("y").compare("mother")==1);
     CHECK(T.find("gd").compare("mother")==1);
     CHECK(T.find("p").compare("mother")==1);
     CHECK(T.find("b").compare("mother")==1);
     CHECK(T.find("v").compare("mother")==1);
     CHECK(T.find("c").compare("mother")==1);
     CHECK(T.find("ead").compare("mother")==1);
     CHECK(T.find("xvc").compare("great-great-grandfather")==1);
     CHECK(T.find("gtre").compare("great-great-grandfather")==1);
     CHECK(T.find("tgr").compare("great-great-grandfather")==1);
     CHECK(T.find("rte").compare("great-great-grandfather")==1);
     CHECK(T.find("fv").compare("great-great-grandfather")==1);
     CHECK(T.find("w").compare("great-great-grandfather")==1);
     CHECK(T.find("e").compare("great-great-grandfather")==1);
     CHECK(T.find(" vd").compare("great-great-grandfather")==1);
     CHECK(T.find("r").compare("great-great-grandfather")==1);
     CHECK(T.find("aa").compare("great-great-grandfather")==1);
     CHECK(T.find("aaa").compare("great-great-grandfather")==1);
     CHECK(T.find("abaea").compare("great-great-grandfather")==1);
     CHECK(T.find("awes").compare("great-great-grandfather")==1);
}