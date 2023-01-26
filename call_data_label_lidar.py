import pandas as pd
import numpy as np

import matplotlib.pyplot as plt
import math
from os.path import expanduser as os
def plot_check_cluster(i_number):
    zero = "0"
    if len(str(i_number)) >1:
        zero = ""

    df = pd.read_excel(os('~/neobotix_workspace/src/data_real_lidar_knn/data_'+str(zero)+str(i_number)+'.xls'))
    x_list = df['x'].tolist()
    y_list = df['y'].tolist()
    epc = df['end_point_cluster'].tolist()
    epc_list = []
    for i in range(len(epc)):
        if math.isnan(epc[i]) == False:
            epc_list.append(epc[i])
    print("epc_list : "+str(epc_list))
    color = ["b","g","r","c","m","y","k","w"]
    # plt.plot(x_list,y_list,(""))
    # plt.legend()
    # plt.show()
    point_1 = [0,0]
    point_2 = [0,0]
    point_3 = [0,0]
    er_tp = 0.004
    h_t = 0.11
    b_t = 0.25
    center_list = []

    # for i in range(len(x_list)):
    #     point_1[0] = x_list[i]
    #     point_1[1] = y_list[i]

    #     point_2[0] = point_1[0]-h_t
    #     point_2[1] = point_1[1]-b_t/2

    #     point_3[0] = point_1[0]+h_t
    #     point_3[1] = point_1[1]-b_t/2

    #     plt.plot(point_2[0],point_2[1],"k*")
    #     plt.plot(point_3[0],point_3[1],"y*")

    #     for j in range(len(x_list)):
            
    #             x_d_p = math.pow((x_list[j]-point_2[0]),2)
    #             y_d_p = math.pow((y_list[j]-point_2[1]),2)
    #             dis = math.sqrt(x_d_p+y_d_p)
    #             if (dis <= er_tp):
    #                 x_d_p = math.pow((x_list[j]-point_2[0]),2)
    #                 y_d_p = math.pow((y_list[j]-point_2[1]),2)
    #                 dis = math.sqrt(x_d_p+y_d_p)
    #                 if (dis <= er_tp):
    #                     print("JESUSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS : "+str(j)+"  file : "+str(i_number))
    #                     center_list.append(i)
    #                     pass
                

    spc = 0 
    color_num = 0
    checker = 0
    cusor = 0
    
    for i in range(len(epc_list)):
        length = int(epc_list[i]-spc)
        # print(length)
        for j in range(int(length)):
            
            cusor = int(spc+j)
            plt.plot(x_list[cusor],y_list[cusor],str(color[color_num])+"o")
            
            # print (cusor)
            if checker != cusor:
                print("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF")
            checker = cusor+1
            pass

        spc = epc_list[i]
        print("color_num : "+str(color_num))
        color_num += 1 
        if color_num == 8:
            color_num = 0
    print(center_list)
    for i in range(len(center_list)):
        plt.plot(x_list[center_list[i]],y_list[center_list[i]],"rd")
    plt.show()

def main(args=None):
    start_file = 1
    end_file = 50    
    lenght_file = end_file - start_file + 1
    current_file = start_file
    for i in range(lenght_file):
        print("-----------------------------------------------------------------------------------------")
        print("-----------------------------------------------------------------------------------------")
        print("current_file : " + str(current_file))
        plot_check_cluster(current_file)
        current_file += 1
    
# print()
if __name__ == '__main__':
    main()

    # plt.legend()
    # plt.show()