# G4-Brems

Release v1.0.0

A Geant4 Model of Bremsstrahlung or "braking radiation." In this model I will mimic the production of Bremsstrahlung by shooting electrons at a tungsten target and detect the energies of the resulting x-ray photons. 


# Measurements
- Electron energies = 6 MeV or 10 MeV based on the equation $U (V) = E_{electron} (eV)$ [1](#sources) In other words, a 6 MV beam of a linac would produce 6 MeV electrons.
- Electron beam width: 1 mm [2](#sources)
- From target to detector: 10 mm


# Sources
- 1: [Bremsstrahlung article](https://folk.ntnu.no/floban/KJ%20%203055/X%20%20Ray/Bremsstrahlung.htm)
- 2: [How a Linear Accelerator Works Video (03:00)](https://www.youtube.com/watch?v=jSgnWfbEx1A)

# Git with this remote branch
This is the release-v1.0.0 branch. In order to make changes to this branch, follow these steps:
```git
git clone https://github.com/john9francis/G4-Brems.git
```
First, checkout the correct branch
```git
git checkout remotes/origin/release-v1.0.0
```
You can also see a list of the branches by running,
```git
git branch -a
```
And then check that you are on the correct branch with,
```git
git branch
```

Once you are on the branch, add and commit like normal. But to push and pull, you have to specifically target the branch.

To pull to the specific branch, 
```git
git pull origin release-v1.0.0
```
To push to the specific branch,
```git
git push origin HEAD:release-v1.0.0
```

# Credit to Geant4
- [Geant4 website](https://geant4.web.cern.ch/)

    Recent Developments in Geant4, J. Allison et al., Nucl. Instrum. Meth. A 835 (2016) 186-225
    Geant4 Developments and Applications, J. Allison et al., IEEE Trans. Nucl. Sci. 53 (2006) 270-278
    Geant4 - A Simulation Toolkit, S. Agostinelli et al., Nucl. Instrum. Meth. A 506 (2003) 250-303
