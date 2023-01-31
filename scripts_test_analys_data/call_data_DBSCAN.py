start_file = 1
end_file = 121
date_data = "26-01-66" #"DD-MM-YY"
break_al = 0
import pandas as pd
import numpy as np

import matplotlib.pyplot as plt
import math
from os.path import expanduser as os
import numpy as np
from sklearn.cluster import DBSCAN
from sklearn import metrics
def plot_check_cluster(i_number):
    zero = "0"
    if len(str(i_number)) >1:
        zero = ""

    df = pd.read_excel(os('~/neobotix_workspace/src/liadr_test_data_'+date_data +'/data_'+str(zero)+str(i_number)+'.xls'))
    x_list = (df['x'].tolist())
    y_list = (df['y'].tolist())
    # x_list_100 = x_list*100
    # for i in range(len(x_list)):
    #     # x_list_100.append(x_list[i]*100)
    
    color = ["b","g","r","c","m","y","k","w"]

    cluster_dict = lidar_DBscan(x_list,y_list,eps_value=0.05,min_samples_value=5,show_plot = 0)
    
    # print(cluster_dict[1])
    x_new,y_new = x_list[min(cluster_dict[1]):max(cluster_dict[1])],y_list[min(cluster_dict[1]):max(cluster_dict[1])]
    # lidar_DBscan(x_new,y_new,eps_value=0.02,min_samples_value=5,show_plot = 1)

    # fig = plt.gcf()
    # ax = fig.gca()
    # top_point = y_new.index(max(y_new))
    # circle2 = plt.Circle((x_new[top_point], y_new[top_point]), 0.2, color='b', fill=False)

        
    # ax = plt.gca()
    # ax.cla() # clear things for fresh plot
    # ax.add_patch(circle2)
    
    # ax.plot(x_new,y_new,"ro",)
    # ax.plot(x_list,y_list,"go",)

    # plt.plot(x_new,y_new,"ro")
    
    dis_point = 1
    cluster_num = 1
    e_d = 0.02

    end_point_cluster = []
    for i in range(len(x_new)-dis_point):
        x_d_p = math.pow((x_new[i]-x_new[i+dis_point]),2)
        y_d_p = math.pow((y_new[i]-y_new[i+dis_point]),2)
        dis = math.sqrt(x_d_p+y_d_p)
        if (dis > e_d):
            cluster_num +=1
            # print(i)
            end_point_cluster.append(i)
            # plt.plot(x_new[i],y_new[i],"gx")
    # end_point_cluster.append(len(x_new)-1)
    # plt.plot(y[len(x_new)-1],x_new[len(x_new)-1],"gx")
    # plt.show()
    # print(y_new)
    slope = []
    l = 2
    for i in range(len(x_new)-l):
        slope.append((y_new[i+l]-y_new[i])/(x_new[i+l]-x_new[i]))
    # print(slope) 
    # plt.plot(x_list,y_list,"bx")

    # for i in range(len(slope)):
    #     if abs(slope[i]) < 0.3 :
    #         plt.plot(x_new[i],y_new[i],"ro")
    # plt.show()
    # print(cluster_dict[1])
    # cluster_dict_2 = lidar_DBscan(x_new,y_new,eps_value=0.02,min_samples_value=2,show_plot = 1)
    # print(len(cluster_dict))
    
    dis_list = []
    for i in range(len(cluster_dict)-1):
        # print(cluster_dict[i])

        # print(x_list[x_list.index(max(cluster_dict[i]))])
        # print(y_list[y_list.index(max(cluster_dict[i]))])
        # print(min(cluster_dict[i]))
        # print(max(cluster_dict[i]))
        
        pow_dis_x = (x_list[max(cluster_dict[i])]-x_list[min(cluster_dict[i])])**2
        pow_dis_y = (y_list[max(cluster_dict[i])]-y_list[min(cluster_dict[i])])**2
        dis_xy = math.sqrt(pow_dis_x+pow_dis_y)

        print(dis_xy)
        if dis_xy <= 0.5:
            if dis_xy >= 0.4:
                dis_list.append(dis_xy)
                
        line_dis_x = [x_list[min(cluster_dict[i])], x_list[max(cluster_dict[i])]]
        line_dis_y = [y_list[min(cluster_dict[i])],y_list[max(cluster_dict[i])]]
        # print(x_list[min(cluster_dict[i])])
        # print(x_list[0])
        # print(line_dis_x)
        # print(line_dis_y)
        plt.plot(line_dis_x,line_dis_y,"r")
    if (len(dis_list)) == 0:
        dis_list.append(200)
    if (len(dis_list)) > 1:
        dis_list.append(300)
    return dis_list


# eps=0.04, min_samples=5
def lidar_DBscan(x_list,y_list,eps_value=0.04,min_samples_value=5,show_plot = 1):
    lidar_list = []
    for i in range(len(x_list)):

        lidar_list.append([x_list[i],y_list[i]])

    liadar_array = np.array(lidar_list)

    # print(type(liadar_array))
    db = DBSCAN(eps=eps_value, min_samples=min_samples_value ).fit(liadar_array)
    labels = db.labels_
    n_clusters_ = len(set(labels)) - (1 if -1 in labels else 0)
    n_noise_ = list(labels).count(-1)

    print("Estimated number of clusters: %d" % n_clusters_)
    print("Estimated number of noise points: %d" % n_noise_)


    plt.title("Estimated number of clusters: {n_clusters_}")
    # print( "labels : "+str(db.labels_ ))
    # print(len(db.labels_))
    # print(len(x_list))
    # print(" : "+str(db.leaf_size))

    cluster_dict = {}
    # cluster_dict[-1]=[1,2]
    # cluster_dict.append("a")
    # print(cluster_dict)
    for i in range(-1,max(labels)+1):
        stack = []
        for j in range(len(labels)):
            if labels[j] == [i]:
                stack.append(j)
        # print(i)
        cluster_dict[i]=stack
    
    
        






    if show_plot == 1:
        unique_labels = set(labels)
        core_samples_mask = np.zeros_like(labels, dtype=bool)
        core_samples_mask[db.core_sample_indices_] = True

        colors = [plt.cm.Spectral(each) for each in np.linspace(0, 1, len(unique_labels))]
        for k, col in zip(unique_labels, colors):
            if k == -1:
                # Black used for noise.
                col = [0, 0, 0, 1]

            class_member_mask = labels == k

            xy = liadar_array[class_member_mask & core_samples_mask]
            plt.plot(
                xy[:, 0],
                xy[:, 1],
                "o",
                markerfacecolor=tuple(col),
                markeredgecolor="k",
                markersize=14,
            )

            xy = liadar_array[class_member_mask & ~core_samples_mask]
            plt.plot(
                xy[:, 0],
                xy[:, 1],
                "o",
                markerfacecolor=tuple(col),
                markeredgecolor="k",
                markersize=6,
            )
        plt.show()
    return cluster_dict 


def main(args=None):
    # start_file = 1
    # end_file = 50    
    dis_list = []
    lenght_file = end_file - start_file + 1
    current_file = start_file
    for i in range(lenght_file):
        print("-----------------------------------------------------------------------------------------")
        print("-----------------------------------------------------------------------------------------")
        print("current_file : " + str(current_file))
        dis_list.append(plot_check_cluster(current_file))
        current_file += 1
    print("num_dis_list"+str(len(dis_list)))
    print(dis_list)
    for i in range(len(dis_list)):
        if dis_list[i].find(200):
            print("error : file "+str(i)+"cannot find charger")
        if dis_list[i][0].find(200):
            print("error : file "+str(i)+"charger more than 1")

    
# print()
if __name__ == '__main__':
    main()

    # plt.legend()
    # plt.show()