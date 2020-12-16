# AlexEval
====
Evaluation software for single molecule FRET measurements with alternating laser excitation


Introduction
---
This software performs data analysis of single molecule FRET measurements. The goal was to develop a GUI that can handle photon counting data from a confocal microscope with two detection channels and alternating laser excitation. AlexEval can perform
- reading of .t3r files (that include markers for laser alternation)
- burst search
- burst filtering
- display 2D FRET histograms (proximity ratio vs. stoichiometry ratio)
- subpopulation filtering
- Gaussian Mixture Model fitting to 2D histograms
- species-selective fluorescence correlation spectroscopy (FCS)


Exemplary usage can be found here: 
https://doi.org/10.11588/heidok.00022135


The software is also available as a plugin for QuickFit3.0
https://github.com/jkriege2/QuickFit3/tree/master/plugins/qfe_alexeval


Requirements
---
This program was written using Qt 4.8.4 and QtDesigner x.x under Windows.

This program uses the eigen library, the GSL library, and relies heavily on code developed for QuickFit 3.0 (SVN: 1959) by Jan Krieger.
QuickFit 3.0 can be obtained from https://github.com/jkriege2/QuickFit3.



Acknowledgements
---
This program was developed at the Division of Biophysics of Macromolecules at the German Cancer Research Center (DKFZ) in Heidelberg under supervision of Prof. Jörg Langowski. 
I would like to thank Alexander Gansen for co-supervising the project, Jan Krieger for programming help, and Tillmann Kaudse for his analysis routine that served as a starting point for this program.


