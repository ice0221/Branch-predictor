# Branch-predictor
Use C++ language finish simple algorithm about Branch predictor.
The version_1 is finished in 2021/05/14
## Input Rule
1. Use "N" or "T"

## Input
```
TTTTNNTNTNTNTNTNT
```
## Output
```
(00,SN,SN,SN,SN) wrong
(01, WN, SN, SN, SN) wrong
(11, WN, WN, SN, SN) wrong
(11, WN, WN, SN, WN) wrong
(11, WN, WN, SN, WT) wrong
(10, WN, WN, SN, WN) correct
(00, WN, WN, SN, WN) wrong
(01, WT, WN, SN, WN) wrong
(10, WT, WT, SN, WN) wrong
(01, WT, WT, WN, WN) wrong
(10, WT, WN, WN, WN) wrong
(01, WT, WN, WT, WN) wrong
(10, WT, WT, WT, WN) correct
(01, WT, WT, ST, WN) wrong
(10, WT, WN, ST, WN) correct
(01, WT, WN, ST, WN) wrong
(10, WT, WT, ST, WN) correct
(01, WT, WT, ST, WN) correct
```

