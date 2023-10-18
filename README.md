# COMPILATION

To compile the code run the following commands:

```bash
cmake -S . -B build
cmake --build build
./build/peg
```

# GENERAL FUNCTIONING AND STRUCTURE

The program simulates the Galton board implementing shocks between pegs and particles.
It relies on pure mechanics therefore position and velocity of the particle is calculated by integrating the equation of motion according to Euler method at each fixed time step (you can choose whatever time step you desire, by default it is set to $0.01s$, keep in mind that the higher the time step the lower the precision of the calculus of position and velocity, on the other hand be careful to decrease too much the time step as well because it will slow the execution of the program).
It generates a chosen number of particles independently and consequentially to one another (by default the number is 1000, but feel free to choose the one of interest, see following section to know how).
Particles are generated at a fixed initial height, and with an initial velocity (by default `4` and `(0,0)`) (you can change those as well). The initial $x$ position of the particles is randomly generated between a range of values (by default between `3.` And `5.`) according to a uniform distribution. Of course you can edit the extremes of interval of generation but as well change the random distribution that generates the values.
The program simulates Shocks between particles and pegs both elastic and partially inelastic. (See the following section to know how to choose the amount of kinetic energy conserved after a single shock… be careful)
Particles will bounce on pegs and eventually end up at `height=0` and enter one of the columns that underly the last row of pegs.
Of course shocks between particles and lateral walls was implemented as well.
You can choose the width of the board by setting the $x$ position of lateral walls (by default they are set to `0` and `8`) and can as well choose the number of columns the particles fall into, they will have all the same width.
While running a series of rows of evenly spaced numbers will be displayed on the terminal.
Take one row for example, each number in the row will represent the number of particles landed in the corresponding column so far.
Obviously the amount of numbers that appear in a single row correspond to the number of columns you chose to collect the particles in.
The last row displayed before the end of the program represent the final distribution of particles in columns.

# HOW TO SET YOUR VALUES:

-   Set number of generated particles: in `main.cpp`, line `22`, change the condition of the for cycle, changing 1000 with the desired number.

-   Set range initial x-position: In `main.cpp`, line `26`, change the extremes of the distribution.

-   Set default values for particle (initial height, initial velocity): In `main.cpp`,line `29`, first value is the mass (unnecessary for this program), the second argument is the radius of the particles(default set to `0.2`) the third argument is the vector of initial position, first component is set by the random generation and the second is the initial heigh (set accordingly to the disposition of pegs and with physical sense), third argument is the initial velocity (set to `(0,0)`) you can choose if you want, maybe it would be interesting to generate randomly their components.

-   Set time step of integration:
    In `main.cpp`, line `33`, in the third argument of the constructor of eng change the time step as you want (keep in mind the warnings told in previous section)

-   Set configuration (pegs and width and number of columns):
    You can create your own Galton configuration: you can chose peg’s disposition and radius and $x$ position of lateral walls and the number of column. Set these parameters coherently with one another taking into account the radius of particles!
    In configuration.cpp, create a function `configuration3()` for example, take as example the other two configuration functions!

-   Set kinetic energy:
    In `particle.cpp`, in `velocity_shock_changer`, in line `34`, change the coefficients set to `1` and `0.5` by default before the components of the `Bbase_final_velocity_vector_component`.
    **WARNING: DO NOT CHANGE THE MINUS IN FRONT OF THE SECOND COMPONENT** (it is necessary to run the program correctly)
    (It would be interesting to conserve the kinetic energy on the $x$ component and change it on $y$ one).

Keep attention to all the warnings previously told!
