### Superposition Wave Function Visualization for free particle

This is a cross platform software that visualizes the **Amplitude**(the square root of **PDF**) and  **Phase** of a superposition wave function for a free particle in 1 dimension <code>x</code> 

This work is done as a bonus project for the Quantum Electronics Course of *[KN Toosi University of Technology](https://en.kntu.ac.ir), Tehran, Iran*, presented by [Dr. Ebrahim Nadimi](https://wp.kntu.ac.ir/nadimi/) (Special Thanks to Dr Nadimi for the excellent lectures that caused a solid understanding on Quantum Physics in me, and the guidance to do this projects)

#### General Description

The Schrodinger Equation is:

![SE](https://latex.codecogs.com/svg.image?i\hbar&space;\frac{\partial}{\partial&space;t}&space;\Psi(x,t)&space;=&space;\left[&space;-\frac{\hbar^2}{2m}\Delta&space;&plus;&space;V(x,t)&space;\right]&space;\Psi(x,t))

in a *1D* case, any linear composition of complex exponentials can be a solution to the SE:

<img src="https://latex.codecogs.com/svg.image?\Psi(x,t)&space;=&space;\sum_{n=1}^{N}&space;A_n&space;\exp&space;i(k_nx-\omega_nt)" title="\Psi(x,t) = \sum_{n=1}^{N} A_n \exp i(k_nx-\omega_nt)" />

while we can specify the correct relation between the **wave number** and the **angular frequency** (with the Energy associated with each state)

<img src="https://latex.codecogs.com/svg.image?\hat{H}\Psi&space;=&space;E&space;\Psi&space;" title="\hat{H}\Psi = E \Psi " />

<img src="https://latex.codecogs.com/svg.image?V(x,t)&space;=0" title="V(x,t) =0" />

<img src="https://latex.codecogs.com/svg.image?E_n&space;=&space;\frac{k_n^2&space;\hbar^2}{2m}" title="E_n = \frac{k_n^2 \hbar^2}{2m}" />

<img src="https://latex.codecogs.com/svg.image?\omega_n&space;=&space;\frac{E_n}{\hbar}" title="\omega_n = \frac{E_n}{\hbar}" />

The **Born's rule** helps us to find the coefficients; considering that the complex exponentials are *orthonormal*, we can arbitrarily choose the coefficients so that:

<img src="https://latex.codecogs.com/svg.image?\sum_{n}&space;|A_n|^2&space;=&space;1" title="\sum_{n} |A_n|^2 = 1" />

we can choose the coefficients so that the state would be equally weighted:

<img src="https://latex.codecogs.com/svg.image?A_n&space;=&space;\frac{1}{\sqrt{N}}" title="A_n = \frac{1}{\sqrt{N}}" />



#### Mathematical Calculations

The Amplitude

<img src="https://latex.codecogs.com/svg.image?\Psi(x,t)&space;=&space;r(x,t)&space;\exp[{i\phi(x,t)}]" title="\Psi(x,t) = r(x,t) \exp[{i\phi(x,t)}]" />

<img src="https://latex.codecogs.com/svg.image?|\Psi|^2&space;=&space;\Psi&space;\times&space;\Psi^*&space;\Rightarrow&space;r(x,t)&space;=&space;\sqrt{\Psi&space;\times&space;\Psi^*}" title="|\Psi|^2 = \Psi \times \Psi^* \Rightarrow r(x,t) = \sqrt{\Psi \times \Psi^*}" />

<img src="https://latex.codecogs.com/svg.image?\Psi&space;\times&space;\Psi^*&space;=&space;\frac{1}{N}\sum_{n,m}\exp&space;i\left[&space;(k_n-k_m)x-(\omega_n-\omega_m)t&space;\right]" title="\Psi \times \Psi^* = \frac{1}{N}\sum_{n,m}\exp i\left[ (k_n-k_m)x-(\omega_n-\omega_m)t \right]" />

And there are `N` terms with `n=m` so:

<img src="https://latex.codecogs.com/svg.image?\Psi&space;\times&space;\Psi^*&space;=&space;1&space;&plus;&space;\frac{1}{N}\sum_{n&space;\ne&space;m}\exp&space;i\left[&space;(k_n-k_m)x-(\omega_n-\omega_m)t&space;\right]" title="\Psi \times \Psi^* = 1 + \frac{1}{N}\sum_{n \ne m}\exp i\left[ (k_n-k_m)x-(\omega_n-\omega_m)t \right]" />

The other `N(N-1)` terms are splittable in two groups in which each term in a group is corresponded to exactly one term in the other group, so that the corresponded terms are complex conjugate of each other (As we know for any `(n,m)` term, there is a `(m,n)` term):

<img src="https://latex.codecogs.com/svg.image?P(x,t)&space;=&space;\Psi&space;\times&space;\Psi^*&space;=&space;1&plus;\frac{2}{N}\sum_{n=1}^N&space;\sum_{m=n&plus;1}^N&space;\cos&space;\left[&space;(k_n-k_m)x-(\omega_n-\omega_m)t&space;\right]" title="P(x,t) = \Psi \times \Psi^* = 1+\frac{2}{N}\sum_{n=1}^N \sum_{m=n+1}^N \cos \left[ (k_n-k_m)x-(\omega_n-\omega_m)t \right]" />

And the **Born's rule** will be satisfied, while the integral of a `cosine` on a period is `0` 

The phase

<img src="https://latex.codecogs.com/svg.image?Im(\Psi)&space;=&space;\frac{\Psi-\Psi^*}{2i},&space;Re(\Psi)&space;=&space;\frac{\Psi&plus;\Psi^*}{2}" title="Im(\Psi) = \frac{\Psi-\Psi^*}{2i}, Re(\Psi) = \frac{\Psi+\Psi^*}{2}" />

<img src="https://latex.codecogs.com/svg.image?\phi(x,t)&space;=&space;tg^{-1}(\frac{\Psi-\Psi^*}{\Psi&plus;\Psi^*})" title="\phi(x,t) = tg^{-1}(\frac{\Psi-\Psi^*}{\Psi+\Psi^*})" />

<img src="https://latex.codecogs.com/svg.image?\phi(x,t)&space;=&space;tg^{-1}(\frac{\sum_{n=1}^N&space;\sin&space;(k_nx-\omega_n&space;t)}{\sum_{n=1}^N&space;\cos&space;(k_nx-\omega_n&space;t)})" title="\phi(x,t) = tg^{-1}(\frac{\sum_{n=1}^N \sin (k_nx-\omega_n t)}{\sum_{n=1}^N \cos (k_nx-\omega_n t)})" />


#### Software Description

![a preview of the software](shot.png)

This numerical calculations are done using pure C++ and the STL (cmath)

The graphical application is wrote using Qt5 and to visualize and plot the results, QCustomPlot is used

#### inputs

​	**K array** comma separated

​	**x range** the calculation range

​	**number of points in x range**

​	**time variation speed**

​	**The particle mass** and a push button to set the default electron mass

​	**result type** you can choose which one to plot: sqrt(PDF), PDF, PDF with complex implementation (similar to real implementation)





#### Supsupplementary Description

To cover a possibility of wrong mathematical calculations for series and wrong programming algorithms, programming implementation with complex numbers has been done and the results was similar to the implementation with the series of `cosines`.  



#### some tests

As  you can see in the tests below, increasing number of harmonics, will increase the period value.

and from the last image (more resolution in x) we can see that the derivative of PDF is continuous 

![a preview of the software](res_1.png)

![a preview of the software](res_2.png)

![a preview of the software](res_3.png)

![a preview of the software](res_4.png)

![a preview of the software](res_5.png)
