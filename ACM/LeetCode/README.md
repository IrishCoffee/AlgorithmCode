1. remove duplicates from sorted array
保持一个current变量，如果和current相同，说明有duplicate，那么后面所有的元素都需要往前挪。
如果和current不同而且没有duplicate，就更新。
如果和current不同而且有duplicate，就把此元素放到pointer的位置上，pointer位置+1.
