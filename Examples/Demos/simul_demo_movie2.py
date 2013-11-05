'''
Simulation demo: make movie
'''

import os, sys, numpy, pylab, matplotlib

from libBornAgainCore import *

radius = 1
layer_thickness = 1
Nframes = 100
Ngrowframes = 30

# ----------------------------------
# describe sample and run simulation
# ----------------------------------
def RunSimulation():
    # defining materials
    mAir = MaterialManager.getHomogeneousMaterial("Air", 0.0, 0.0)
    mSubstrate = MaterialManager.getHomogeneousMaterial("Substrate", 6e-6, 2e-8)
    mParticle = MaterialManager.getHomogeneousMaterial("Particle", 6e-4, 2e-8)

    # collection of particles
    semisphere_ff = FormFactorSphere(radius, radius)
    semisphere = Particle(mParticle, semisphere_ff)
    particle_decoration = ParticleDecoration()
    particle_decoration.addParticle(semisphere)

    # interference function
    interference = InterferenceFunction1DParaCrystal(6 * nanometer, 1 * nanometer)
    particle_decoration.addInterferenceFunction(interference)

    # air layer with particles and substrate form multi layer
    air_layer = Layer(mAir)
    air_layer.setDecoration(particle_decoration)
    film_layer = Layer(mParticle, layer_thickness)
    substrate_layer = Layer(mSubstrate)
    multi_layer = MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(film_layer)
    multi_layer.addLayer(substrate_layer)

    # build and run experiment
    simulation = Simulation()
    simulation.setDetectorParameters(100, -4.0 * degree, 4.0 * degree, 100, 0.0 * degree, 8.0 * degree)
    simulation.setBeamParameters(1.0 * angstrom, 0.2 * degree, 0.0 * degree)
    simulation.setSample(multi_layer)
    simulation.runSimulation()
    # intensity data
    return simulation.getIntensityData().getArray()

def SetParameters(i):
    global radius
    global layer_thickness
    if i<Ngrowframes:
        radius = (1. + (3.0/Ngrowframes)*i) * nanometer
        layer_thickness = 0.01 * nanometer
    else:
        radius = 4. * nanometer
        layer_thickness = (0.01 + (0.5/(Nframes-Ngrowframes))*(i-Ngrowframes)) * nanometer

#-------------------------------------------------------------
# main()
#-------------------------------------------------------------
if __name__ == '__main__':
    files = []
    fig = pylab.figure(figsize=(5,5))
    ax = fig.add_subplot(111)
    for i in range(Nframes):
        SetParameters(i)
        result = RunSimulation() + 1 # for log scale
        ax.cla()
        im = ax.imshow(numpy.rot90(result, 1), vmax=1e3,
                 norm=matplotlib.colors.LogNorm(),
                 extent=[-4.0, 4.0, 0, 8.0])
        pylab.xlabel(r'$\phi_f$', fontsize=20)
        pylab.ylabel(r'$\alpha_f$', fontsize=20)
        if i==0:
            pylab.colorbar(im)
        fname = '_tmp%03d.png'%i
        print 'Saving frame', fname
        fig.savefig(fname)
        files.append(fname)
    os.system("mencoder 'mf://_tmp*.png' -mf type=png:fps=10 -ovc lavc -lavcopts vcodec=wmv2 -oac copy -o animation2.mpg")
    print 'Removing temporary files'
    os.system("rm _tmp*")
