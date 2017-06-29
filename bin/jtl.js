*SFQ Circuit
*
L1 1 2 10PH
R1 2 0 1e-12OHM
B1 0 1 JJMOD1
B2 0 2 JJMOD2

.model jjmod1 jj(vg=2.5mv, cap=0.6pf, icrit=100ua)
.model jjmod2 jj(vg=2.5mv, cap=0.6pf, icrit=100ua)
*v1 must equal 0 for some reason
V2 0 1 pulse(0mv 1mv 500ps 2ps 40ps 2ps 500ps)
I2 0 1 pwl(0ps 0ma 1ps 1ma)
I3 0 2 pwl(0ps 0ma 1ps 1ma)
*v2 1 0 sin(0 1mv 1meghz 0us 0)
*
*.tran 500ps 34ns
*.print tran v(1) v(2) i(v1)
.tran 1ps 2ns 200ps 0.5ps
.file V2V
.print DEVV V2

*
.end

