s/ c_double / c_float /g
s/ C_DOUBLE / C_FLOAT /g
s/ c_double[ ]*$/ c_float/g
s/ C_DOUBLE[ ]*$/ C_FLOAT/g
s/(c_double)/(c_float)/g
s/(C_DOUBLE)/(C_FLOAT)/g
s/_double[ ]*$/_single/g
s/_double,/_single,/g
s/_double /_single /g
s/_double(/_single(/g
s/_DOUBLE[ ]*$/_SINGLE/g
s/_DOUBLE,/_SINGLE,/g
s/_DOUBLE /_SINGLE /g
s/_DOUBLE(/_SINGLE(/g
s/dvalues/svalues/g
s/D+0/E+0/g
s/0d0/0e0/g
s/real_bytes = 8/real_bytes = 4/g
s/MA27ID/MA27I/g
s/MA27AD/MA27A/g
s/MA27BD/MA27B/g
s/MA27CD/MA27C/g
s/MA27QD/MA27Q/g
s/MA33ID/MA33I/g
s/MA33AD/MA33A/g
s/MA33CD/MA33C/g
s/MC20AD/MC20A/g
s/MC13ED/MC13E/g
s/MA61AD/MA61A/g
s/MA77AD/MA77A/g
s/MC61AD/MC61A/g
s/MC77AD/MC77A/g
s/MC21BD/MC21B/g
s/symmetric_linear_solver = "ssids"/symmetric_linear_solver = "sytr "/g
s/definite_linear_solver = "ssids"/definite_linear_solver = "sytr "/g
