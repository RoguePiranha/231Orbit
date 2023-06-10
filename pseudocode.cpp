// hit detection pseudocode for bullets, fragments, satellites, and parts
// Check collision between bullets to parts, fragments, and satellites
Program::hitDetection()

    FOR EACH bullet in bullets
        FOR EACH satellite in satellite
              IF linked == True
                   FOR EACH piece in satellite.getPieces
                        IF bullet.position == piece.position
                              FOR EACH piece in satellite.getPieces
                                   piece.updatePosition
              ELSE
                   FOR EACH piece in satellite.getPieces
                        satellite.removePiece



// update position pseudocode for bullets, fragments, satellites, and parts
// updates each element's x and y position based on its dx and dy
Program::updateElementPos()

   FOR EACH bullet in bullets
         bullet.updatePosition

   FOR EACH satellite in satellites
         satellite.updatePosition

   ship.updatePosition
   ship.applyThrust

Element::updatePosition()
    element.x += element.dx
    element.y += element.dy


// TEST CASES
// Test cases for hitDetection
setup()
    // create a bullet x6
    // create a sputnik
    // create a gps
    // create a starlink
    // create a crew dragon
    // create a hubble
    // create a dream chaser

    // set the bullet's position to the sputnik's position
    // set the bullet's position to the gps's position
    // set the bullet's position to the starlink's position
    // set the bullet's position to the crew dragon's position
    // set the bullet's position to the hubble's position
    // set the bullet's position to the dream chaser's position


exercise()
    // call hitDetection
    // assert that sputnik is set to dead
    // assert that the gps is set to dead
    // assert that the starlink is set to dead
    // assert that the crew dragon is set to dead
    // assert that the hubble is set to dead
    // assert that the dream chaser is set to dead


verify()
    // expected output:
    // sputnik is dead
    // gps is dead
    // starlink is dead
    // crew dragon is dead
    // hubble is dead
    // dream chaser is dead


// Test cases for the updatePosition function

setup()
    // create a sputnik
    // create a gps
    // create a starlink
    // create a crew dragon
    // create a hubble
    // create a dream chaser

    // set the sputnik's position to (21082000, 36515095)
    // set the gps's position to (31028540, 25640844)
    // set the starlink's position to (-21082000, -36515095)
    // set the crew dragon's position to (-31028540, -25640844)
    // set the hubble's position to (41296700, 51230489)
    // set the dream chaser's position to (-450, 450)

    // set the sputnik's dx to 2000
    // set the gps's dx to 2000
    // set the starlink's dx to 2000
    // set the crew dragon's dx to 2000
    // set the hubble's dx to 2000
    // set the dream chaser's dx to 2000

    // set the sputnik's dy to 2000
    // set the gps's dy to 2000
    // set the starlink's dy to 2000
    // set the crew dragon's dy to 2000
    // set the hubble's dy to 2000
    // set the dream chaser's dy to -2000

exercise()
    // call updatePosition
    // assert that the sputnik's position is (21084000, 36517095)
    // assert that the gps's position is (31030540, 25642844)
    // assert that the starlink's position is (-21080000, -36513095)
    // assert that the crew dragon's position is (-31026540, -25638844)
    // assert that the hubble's position is (41298700, 51232489)
    // assert that the dream chaser's position is ()

    // call updatePosition
    // assert that the sputnik's position is (21086000, 36519095)
    // assert that the gps's position is (31032540, 25644844)
    // assert that the starlink's position is (-21078000, -36511095)
    // assert that the crew dragon's position is (-31024540, -25636844)
    // assert that the hubble's position is (41300700, 51234489)
    // assert that the dream chaser's position is ()

verify()
    // expected output:
    // sputnik's position is (21086000, 36519095)
    // gps's position is (31032540, 25644844)
    // starlink's position is (-21078000, -36511095)
    // crew dragon's position is (-31024540, -25636844)
    // hubble's position is (41300700, 51234489)
    // dream chaser's position is ()
