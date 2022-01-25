### Superposition Wave Function Visualization for free particle

This is a cross platform software that visualizes the **Amplitude**(the square root of **PDF**) and  **Phase** of a superposition wave function for a free particle in 1 dimension <code>x</code> 

#### General Description

The Schrodinger Equation is:
$$
i\hbar \frac{\partial}{\partial t} \Psi(x,t) = \left[ -\frac{\hbar^2}{2m}\Delta + V(x,t) \right] \Psi(x,t)
$$
in a *1D* case, any linear composition complex exponentials can be a solution to the SE:
$$
\Psi(x,t) = \sum_{n=1}^{N} A_n \exp i(k_nx-\omega_nt)
$$
while we can specify the correct relation between the **wave number** and the **angular frequency** (with the Energy associated with each state)
$$
\hat{H}\Psi = E \Psi \\
V(x,t) =0 \\
E_n = \frac{k_n^2 \hbar^2}{2m} \\
\omega_n = \frac{E_n}{\hbar}
$$
The **Born's rule** helps us to find the coefficients; considering that the complex exponentials are *orthonormal*, we can arbitrarily choose the coefficients so that:
$$
\sum_{n} |A_n|^2 = 1
$$
as another consequence of **Born's rule** in this solution, the solution is valid in one period, so the wave function will be integrable and integration of **PDF** on one period, gives `1`

we can choose the coefficients so that the state would be equally weighted:
$$
A_n = \frac{1}{\sqrt{N}}
$$


#### Mathematical Calculations

The Amplitude
$$
\Psi(x,t) = r(x,t) \exp[{i\phi(x,t)}] \\
|\Psi|^2 = \Psi \times \Psi^* \Rightarrow r(x,t) = \sqrt{\Psi \times \Psi^*} \\
\Psi \times \Psi^* = \frac{1}{N}\sum_{n,m}\exp i\left[ (k_n-k_m)x-(\omega_n-\omega_m)t \right]
$$
And there are `N` terms with `n=m` so:
$$
\Psi \times \Psi^* = 1 + \frac{1}{N}\sum_{n \ne m}\exp i\left[ (k_n-k_m)x-(\omega_n-\omega_m)t \right]
$$
The other `N(N-1)` terms are splittable in two groups in which each term in a group is corresponded to exactly one term in the other group, so that the corresponded terms are complex conjugate of each other (As we know for any `(n,m)` term, there is a `(m,n)` term):
$$
\Psi \times \Psi^* = 1+\frac{2}{N}\sum_{n=1}^N \sum_{m=n+1}^N \cos \left[ (k_n-k_m)x-(\omega_n-\omega_m)t \right]
$$
And the **Born's rule** will be satisfied, while the integral of a `cosine` on a period is `0` 

The phase
$$
Im(\Psi) = \frac{\Psi-\Psi^*}{2i}, Re(\Psi) = \frac{\Psi+\Psi^*}{2} \\
\phi(x,t) = tg^{-1}(\frac{\Psi-\Psi^*}{\Psi+\Psi^*}) \\
\phi(x,t) = tg^{-1}(\frac{\sum_{n=1}^N \sin (k_nx-\omega_n t)}{\sum_{n=1}^N \cos (k_nx-\omega_n t)})
$$


 