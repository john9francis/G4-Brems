FROM koichimurakamik6/geant4-runtime

# setting this variable that geant4 can't find
ENV LD_LIBRARY_PATH=/opt/geant4/lib:$LD_LIBRARY_PATH

WORKDIR /g4_brems

COPY . .

RUN mkdir docker_build && \
  cd docker_build && \
  cmake .. && \
  make

ENTRYPOINT [ "./docker_build/G4_Brems" ]