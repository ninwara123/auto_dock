start_file = 1
end_file = 10
date_data = "26-01-66" #"DD-MM-YY"

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
    x_list = df['x'].tolist()
    y_list = df['y'].tolist()

    color = ["b","g","r","c","m","y","k","w"]

    cluster_dict = lidar_DBscan(x_list,y_list,eps_value=0.04,min_samples_value=5,show_plot = 0)
    # print(cluster_dict[1])
    x_new,y_new = x_list[min(cluster_dict[1]):max(cluster_dict[1])],y_list[min(cluster_dict[1]):max(cluster_dict[1])]
    # print(y_new)
    # slope = []
    # for i in range(len(x_new)-1):
    #     slope.append((y_new[i+1]-y_new[i])/(x_new[i+1]-x_new[i]))
    # print(slope) 
    # plt.plot(x_list,y_list,"bx")

    # for i in range(len(slope)):
    #     if abs(slope[i]) < 0.3 :
    #         plt.plot(x_new[i],y_new[i],"ro")
    # plt.show()
    # print(cluster_dict[1])
    # cluster_dict_2 = lidar_DBscan(x_new,y_new,eps_value=0.02,min_samples_value=2,show_plot = 1)


# eps=0.04, min_samples=5
def lidar_DBscan(x_list,y_list,eps_value=0.04,min_samples_value=5,show_plot = 1):
    lidar_list = []
    for i in range(len(x_list)):

        lidar_list.append([x_list[i],y_list[i]])

    liadar_array = np.array(lidar_list)

    # print(type(liadar_array))
    db = DBSCAN(eps=eps_value, min_samples=min_samples_value).fit(liadar_array)
    labels = db.labels_
    n_clusters_ = len(set(labels)) - (1 if -1 in labels else 0)
    n_noise_ = list(labels).count(-1)

    print("Estimated number of clusters: %d" % n_clusters_)
    print("Estimated number of noise points: %d" % n_noise_)


    plt.title(f"Estimated number of clusters: {n_clusters_}")
    print( "labels : "+str(db.labels_ ))
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