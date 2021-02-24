import pybind_example as cpp
import numpy as np


print('1 + 3 =', cpp.add(1, 3))
print('10 - 6.5 =', cpp.subtract(10, 6.5))

l = [0.5, 0.2, 1.0]
print('list:          ', l)
print('increased list:', cpp.increase_list(l))


v = np.asarray([0.5, 1.5, 2.5])
print('v before:', v)
cpp.act_on_a_vector(v)
print('v after: ', v)

w = cpp.return_a_vector(10)
print(w.shape, w)


A = np.asarray([
    [3.0, 1.0, 0.],
    [0.0, 2.0, 0.],
    [1.0, 0.0, 4.]])

z = cpp.matvec(A, v)
print(z.shape, z)


T = np.ones((2, 2, 2))
cpp.act_on_a_tensor(T)
print(T)
