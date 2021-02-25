//################################################################################
//############### Basic C++ - Python bindings ####################################
//################################################################################
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


double add(double i, double j) {
    return i + j;
}

std::vector<double> increase_list(std::vector<double> v){
    for (int i = 0; i < v.size(); ++i) {
        v[i] += 1;
    }
    return v;
}

//################################################################################
//################# Interfacing Eigen and Python without copying data ############
//################################################################################
#include <Eigen/Core>
#include <Eigen/Dense>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
typedef Eigen::VectorXd Vector;
typedef Eigen::Ref<Vector> RefVector;
typedef Eigen::MatrixXd Matrix;
typedef Eigen::Ref<Matrix, 0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> RefMatrix;


void act_on_a_vector(RefVector& v){
    for (int i = 0; i < v.size(); ++i) {
        v[i] += 1;
    }
}

Vector return_a_vector(int n){
    Vector v = Vector(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    return v;
}

Vector matvec(RefMatrix& A, RefVector& v){
    Vector Av = A * v;
    return Av;
}

// ################################################################################
// ######### Interfacing numpy and xtensor without copying data ###################
// ################################################################################
#define FORCE_IMPORT_ARRAY
#include "xtensor/xarray.hpp"
#include "xtensor-python/pyarray.hpp"
typedef xt::pyarray<double> Tensor ;

void act_on_a_tensor(Tensor& v){
    for (int i = 0; i < v.shape(0); ++i) {
        for (int j = 0; j < v.shape(1); ++j) {
            for (int k = 0; k < v.shape(2); ++k ) {
                v(i, j, k) *= 2;
            }
        }
    }
}

namespace py = pybind11;

PYBIND11_MODULE(pybind_example, m) {
    xt::import_numpy();

    m.def("add", &add, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");
    m.def("subtract", [](double i, double j) { return i - j; });
    m.def("increase_list", &increase_list);

    m.def("act_on_a_vector", &act_on_a_vector);
    m.def("return_a_vector", &return_a_vector);
    m.def("matvec", &matvec);

    m.def("act_on_a_tensor", &act_on_a_tensor);
}


