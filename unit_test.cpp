#include "Set.h"
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "Secuencia.h"

BOOST_AUTO_TEST_CASE(unit_test_create_set){
    BOOST_TEST_MESSAGE("Probando creación de set...");
    list<int> l = {1,2,2,4};
    Set set;
    set.create({1,2,2,4});
    BOOST_TEST(l==set.getNums());
    BOOST_TEST_MESSAGE("Set creado exitosamente");
    BOOST_TEST_MESSAGE("Intentando imprimir set...");
    set.print();
    BOOST_TEST_MESSAGE("Intentando agregar elemento con valor 5...");
    set.add(5);
    BOOST_TEST_MESSAGE("Mostrando cambios...");
    set.print();
}

BOOST_AUTO_TEST_CASE(unit_test_create_seq){
    BOOST_TEST_MESSAGE("Probando creación de secuencia...");
    list<int> l = {2,3,4,5};
    Secuencia seq;
    seq.create({2,3,4,5});
    BOOST_TEST(l==seq.getNums());
    BOOST_TEST_MESSAGE("Secuencia creada exitosamente");
    BOOST_TEST_MESSAGE("Intentando imprimir secuencia...");
    seq.print();
    BOOST_TEST_MESSAGE("Intentando agregar elemento con valor 6...");
    seq.add(6);
    BOOST_TEST_MESSAGE("Mostrando cambios...");
    seq.print();
}
BOOST_AUTO_TEST_CASE(unit_test_convert_set){
    BOOST_TEST_MESSAGE("Probando convertir set a secuencia...");
    list<int> l = {1,2,2,4};
    Set set;
    set.create({1,2,2,4});
    set.print();
    Secuencia seq = set.convert();
    BOOST_TEST_MESSAGE("Conversión exitosa");
    seq.print();
    BOOST_TEST_MESSAGE("Cambio de set a secuencia exitoso");
    BOOST_TEST(seq.equals(set));

}

BOOST_AUTO_TEST_CASE(unit_test_convert_seq){
    BOOST_TEST_MESSAGE("Probando convertir de secuencia a set");
    list<int> l = {2,3,4,5};
    Secuencia seq;
    seq.create({2,3,4,5});
    seq.print();
    Set set = seq.convert();
    BOOST_TEST_MESSAGE("Conversión exitosa");
    set.print();
    BOOST_TEST_MESSAGE("Cambio de secuencia a set exitoso");
    BOOST_TEST(set.equals(seq));
}

BOOST_AUTO_TEST_CASE(unit_test_equals_set_to_set){
    BOOST_TEST_MESSAGE("Probando igualdad entre sets...");
    Set set;
    set.create({1,2,2,4,2});
    Set set2;
    set2.create({2,2,4,1,2});
    BOOST_TEST_MESSAGE("Evaluación {1,2,2,4,2} es igual a {2,2,4,1,2}");
    BOOST_TEST(set.equals(set2));
}

BOOST_AUTO_TEST_CASE(unit_test_equals_seq_to_seq){
    BOOST_TEST_MESSAGE("Probando igualdad entre secuencias");
    Secuencia seq;
    seq.create({2,3,4,5});
    Secuencia seq2;
    seq2.create({2,3,4,5});
    BOOST_TEST_MESSAGE("Evaluación (2,3,4,5) es igual a (2,3,4,5)");
    BOOST_TEST(seq.equals(seq2));
}

BOOST_AUTO_TEST_CASE(unit_test_equals_set_to_seq){
    BOOST_TEST_MESSAGE("Probando igualdad entre set y secuencia...");
    Set set;
    set.create({1,2,2,4,2});
    Secuencia seq;
    seq.create({4,2,1});
    BOOST_TEST_MESSAGE("Evaluación {1,2,2,4,2} es igual a (4,2,1)");
    BOOST_TEST(set.equals(seq));
}

BOOST_AUTO_TEST_CASE(unit_test_equals_seq_to_set){
    BOOST_TEST_MESSAGE("Probando igualdad entre secuencia y set");
    Secuencia seq;
    seq.create({2,3,4,5});
    Set set;
    set.create({2,3,3,4,5,5});
    BOOST_TEST_MESSAGE("Evaluación (2,3,4,5) es igual a {2,3,3,4,5,5}");
    BOOST_TEST(seq.equals(set));
}

BOOST_AUTO_TEST_CASE(unit_test_union_set_to_set_and_seq){
    BOOST_TEST_MESSAGE("Verificando unión entre set y set...");
    Set set;
    set.create({1,2,2,4,2});
    set.print();
    Set set2;
    set2.create({3,5,6});
    set2.print();
    list<int> l1 = set.unionOp(set2);
    list<int> l = {1,2,2,4,2,3,5,6};
    BOOST_TEST(l==l1);
    BOOST_TEST_MESSAGE("Verificando unión entre set y secuencia...");
    set2.print();
    Secuencia seq;
    seq.create({4,2,1});
    seq.print();
    l1 = set2.unionOp(seq);
    l = {3,5,6,4,2,1};
    BOOST_TEST(l==l1);
}

BOOST_AUTO_TEST_CASE(unit_test_union_seq_to_seq_and_set){
    BOOST_TEST_MESSAGE("Verificando unión entre secuencia y secuencia...");
    Secuencia seq;
    seq.create({1,2,3});
    seq.print();
    Secuencia seq2;
    seq2.create({3,5,6});
    seq2.print();
    list<int> l1 = seq.unionOp(seq2);
    list<int> l = {1,2,3,5,6};
    BOOST_TEST(l==l1);
    BOOST_TEST_MESSAGE("Verificando unión entre secuencia y set...");
    seq2.print();
    Set set;
    set.create({4,2,2,1});
    set.print();
    l1 = seq2.unionOp(set);
    l = {3,5,6,4,2,1};
    BOOST_TEST(l==l1);
}
BOOST_AUTO_TEST_CASE(unit_test_intersection_set_to_set_and_seq){
    BOOST_TEST_MESSAGE("Verificando intersección entre set y set...");
    Set set;
    set.create({1,2,2,4,2});
    set.print();
    Set set2;
    set2.create({2,4,3,5,6});
    set2.print();
    list<int> l1 = set.intersecOp(set2);
    list<int> l = {2,2,4,2,2,4};
    BOOST_TEST(l==l1);
    BOOST_TEST_MESSAGE("Verificando intersección entre set y secuencia...");
    set2.print();
    Secuencia seq;
    seq.create({4,2,1});
    seq.print();
    l1 = set2.intersecOp(seq);
    l = {2,4,4,2};
    BOOST_TEST(l==l1);
}

BOOST_AUTO_TEST_CASE(unit_test_intersection_seq_to_seq_and_set){
    BOOST_TEST_MESSAGE("Verificando intersección entre secuencia y secuencia...");
    Secuencia seq;
    seq.create({1,2,3,4});
    seq.print();
    Secuencia seq2;
    seq2.create({3,4,5,6});
    seq2.print();
    list<int> l1 = seq.intersecOp(seq2);
    list<int> l = {3,4};
    BOOST_TEST(l==l1);
    BOOST_TEST_MESSAGE("Verificando intersección entre secuencia y set...");
    seq2.print();
    Set set;
    set.create({4,2,2,1,6});
    set.print();
    l1 = seq2.intersecOp(set);
    l = {4,6};
    BOOST_TEST(l==l1);
}