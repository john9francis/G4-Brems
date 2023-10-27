# G4-Brems
A Geant4 Model of Bremsstrahlung or "braking radiation." In this model I will mimic the production of Bremsstrahlung by shooting electrons at a tungsten target and detect the energies of the resulting x-ray photons. 

# How to run on docker
First, pull the docker image
```sh
docker pull john9francis/g4-brems:latest
```
Then, run the container
```sh
docker run --rm -it g4-brems   
```
The entrypoint to the container is bash. This way you can interact with the application as if it's a linux command line. To run the app for example, run these commands:
```sh
cd docker_build
./G4_Brems test_run.mac
```

NOTE: The G4_Brems executable does not work yet, because it tries to open a GUI and I haven't figured that out yet in docker. However, the G4_Brems_terminal works fine to run any commands you want in batch mode. 

For now, running a simulation generates a .root file that can not be viewed within the container. Soon I plan to add root to the container to be able to view the data generated. 

# Measurements

- Electron energies = 6 MeV based on the equation $U (V) = E_{electron} (eV)$ [1](#sources) In other words, a 6 MV beam of a linac would produce 6 MeV electrons.
- Electron beam width: 1 mm [2](#sources)
- Tungsten target=1mm thick and 3cm diameter

<!--
- Graphite electron absorber=1.5cm thick and 3cm diameter
- Tungsten collimator=6.2cm thick, 4 cm inner diameter and 7 cm outer diameter

SETUP 2:
- target-detector distance: 5 cm

-->
# Sources
- 1: [Bremsstrahlung article](https://folk.ntnu.no/floban/KJ%20%203055/X%20%20Ray/Bremsstrahlung.htm)
- 2: [How a Linear Accelerator Works Video (03:00)](https://www.youtube.com/watch?v=jSgnWfbEx1A)

# Credit to Geant4
- [Geant4 website](https://geant4.web.cern.ch/)

- [Recent Developments in Geant4](https://www.sciencedirect.com/science/article/pii/S0168900216306957), J. Allison et al., Nucl. Instrum. Meth. A 835 (2016) 186-225
- [Geant4 Developments and Applications](https://ieeexplore.ieee.org/xpls/abs_all.jsp?isnumber=33833&arnumber=1610988&count=33&index=7), J. Allison et al., IEEE Trans. Nucl. Sci. 53 (2006) 270-278
- [Geant4 - a Simulation Toolkit](https://www.sciencedirect.com/science/article/pii/S0168900203013688), S. Agostinelli et al., Nucl. Instrum. Meth. A 506 (2003) 250-303
