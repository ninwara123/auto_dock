start_file = 31
end_file = 121
date_data = "26-01-66" #"DD-MM-YY"
break_al = 0
show_key = 1
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

    cluster_dict = lidar_DBscan(x_list,y_list,eps_value=0.05,min_samples_value=5,show_plot = 1)
    
    # print(cluster_dict[1])
    x_new,y_new = x_list[min(cluster_dict[1]):max(cluster_dict[1])],y_list[min(cluster_dict[1]):max(cluster_dict[1])]
    # lidar_DBscan(x_new,y_new,eps_value=0.02,min_samples_value=5,show_plot = 1)


    idx_vtx_tri,label_charger = check_charger(x_list,y_list, cluster_dict)


    r_idx_list , l_idx_list = split_r_l_charger(x_list,y_list,cluster_dict,label_charger,idx_vtx_tri)
    cal_theta(x_list,y_list,r_idx_list , l_idx_list)
    # print(ix_v_t)

def cal_theta(x_list,y_list,r_idx_list , l_idx_list):
    ################## will change linear reg for real line *fix
    # x_list
    pass

def split_r_l_charger(x_list,y_list,cluster_dict,label_charger,idx_vtx_tri):

    plt.plot(x_list[idx_vtx_tri],y_list[idx_vtx_tri],"r^")
    fig = plt.gcf()
    ax = fig.gca()
    circle2 = plt.Circle((x_list[idx_vtx_tri],y_list[idx_vtx_tri]), 0.2, color='m', fill=False)
    ax = plt.gca()
    # ax.cla() # clear things for fresh plot
    ax.add_patch(circle2)
    list_idx_charger = cluster_dict[label_charger]
    itls_idx_list = []
    for i in range(len(list_idx_charger)):
        dif_x = x_list[idx_vtx_tri]-x_list[list_idx_charger[i]]
        dif_y = y_list[idx_vtx_tri]-y_list[list_idx_charger[i]]
        pow_dif_x = dif_x**2
        pow_dif_y = dif_y**2
        dis_xy = math.sqrt(pow_dif_x+pow_dif_y)
        if dis_xy <= 0.2 :
            itls_idx_list.append(list_idx_charger[i])
        
    print( itls_idx_list)
    r_idx_list = []
    l_idx_list = []
    point_r_x = []
    point_r_y = []
    point_l_x = []
    point_l_y = []

    for i in range(len(itls_idx_list)):
        if itls_idx_list[i] <= idx_vtx_tri:
            r_idx_list.append( itls_idx_list[i])
            point_r_x.append(x_list[itls_idx_list[i]])
            point_r_y.append(y_list[itls_idx_list[i]])
        if itls_idx_list[i] >= idx_vtx_tri:
            l_idx_list.append( itls_idx_list[i])
            point_l_x.append(x_list[itls_idx_list[i]])
            point_l_y.append(y_list[itls_idx_list[i]])
            
    print("R : "+str(r_idx_list))
    print("L : "+str(l_idx_list))
    print(r_idx_list[-1])

    ################## will change linear reg for real line *fix
    line_r_x = [x_list[r_idx_list[0]],x_list[r_idx_list[-1]]]
    line_r_y = [y_list[r_idx_list[0]],y_list[idx_vtx_tri]]
    line_l_x = [x_list[idx_vtx_tri],x_list[l_idx_list[-1]]]
    line_l_y = [y_list[idx_vtx_tri],y_list[l_idx_list[-1]]]
    plt.xlim([-1.5, 1.5])
    plt.ylim([-0.5,1.5])
    plt.show()
    plt.cla()
    plt.plot(point_r_x,point_r_y,"g^")
    plt.plot(point_l_x,point_l_y,"y*")
    plt.plot(line_r_x,line_r_y,'r')
    plt.plot(line_l_x,line_l_y,'b')
    plt.show()
    return r_idx_list , l_idx_list

def check_charger(x_list,y_list, cluster_dict):
    dis_list = []
    threshold_dis =0.45
    e_dis = 0.07
    index_start_point_cluster = 0
    label_cluster_charger = 0

    for i in range(len(cluster_dict)-1):
        # index_start_point_cluster += cluster_dict[i][cluster_dict[i].index(min(cluster_dict[i]))]
        index_start_point_cluster = cluster_dict[i][0]
        # print(cluster_dict[i])

        # print(x_list[x_list.index(max(cluster_dict[i]))])
        # print(y_list[y_list.index(max(cluster_dict[i]))])
        # print(min(cluster_dict[i]))
        # print(max(cluster_dict[i]))

        dif_x = (x_list[max(cluster_dict[i])]-x_list[min(cluster_dict[i])])
        pow_dif_x = dif_x**2
        dif_y = (y_list[max(cluster_dict[i])]-y_list[min(cluster_dict[i])])
        pow_dif_y = dif_y**2
        dis_xy = math.sqrt(pow_dif_x+pow_dif_y)
        print("dis_xy cluster no."+str(i)+" : "+str(dis_xy))
        
        if abs(dis_xy - threshold_dis) <= e_dis : 

            dis_list.append(dis_xy)
            center_base_x = (x_list[max(cluster_dict[i])]+x_list[min(cluster_dict[i])])/2
            center_base_y  = (y_list[max(cluster_dict[i])]+y_list[min(cluster_dict[i])])/2
            plt.plot(center_base_x,center_base_y,"b^")
            
            slope_charger = dif_y/dif_x
            print("slope_charger : "+str(slope_charger))
            theta_charger = math.atan(slope_charger)
            print("theta_charger : "+str(theta_charger))


            x_rot_z_list = []
            y_rot_z_list = []
            for j in range(len(cluster_dict[i])):
                point_x = x_list[cluster_dict[i][j]]
                point_y = y_list[cluster_dict[i][j]]
                x_rot_z_list.append((point_x*math.cos(theta_charger)) + (point_y*math.sin(theta_charger)))
                y_rot_z_list.append((point_y*math.cos(theta_charger)) - (point_x*math.sin(theta_charger)))

            # print("threshold")
            plt.plot(x_rot_z_list,y_rot_z_list,"cx")
            # print("x_rot_z_list : "+str(x_rot_z_list))
            # print("y_rot_z_list : "+str(y_rot_z_list))
            # print("min x : "+str(x_rot_z_list[x_rot_z_list.index(min(x_rot_z_list))]))
            # print("max x : "+str(x_rot_z_list[x_rot_z_list.index(max(x_rot_z_list))]))

            min_y_rot = y_rot_z_list[y_rot_z_list.index(min(y_rot_z_list))]
            max_y_rot = y_rot_z_list[y_rot_z_list.index(max(y_rot_z_list))]
            min_x_rot = x_rot_z_list[x_rot_z_list.index(min(x_rot_z_list))]

            print("min y : "+str(min_y_rot ))
            print("max y : "+str(max_y_rot))
            plt.plot([min_x_rot,min_x_rot],[min_y_rot,max_y_rot],"m")
            dif_y_rot = max_y_rot-min_y_rot 
            print("dif_y_rot (high triangel measure) : "+str(dif_y_rot))
            if  dif_y_rot >= 0.1 :
                # print("triiiii")
                index_vertex_point_tri_of_list = y_rot_z_list.index(max(y_rot_z_list))
                print("index_vertex_point_tri_of_list : "+str(index_vertex_point_tri_of_list))
                index_vertex_point_tri_of_cluster = index_start_point_cluster+index_vertex_point_tri_of_list 
                print("index_max_point_of_cluster : "+str(index_vertex_point_tri_of_cluster))
                label_cluster_charger = i
                print("label_cluster_charger : "+str(label_cluster_charger))
        # plt.plot(cluster_dict[i][index_vertex_point_tri_of_list])
        line_dis_x = [x_list[min(cluster_dict[i])], x_list[max(cluster_dict[i])]]
        line_dis_y = [y_list[min(cluster_dict[i])], y_list[max(cluster_dict[i])]]
        # print(x_list[min(cluster_dict[i])])
        # print(x_list[0])
        # print(line_dis_x)
        # print(line_dis_y)
        plt.plot(line_dis_x,line_dis_y,"y")
        
    
    print("dis_list"+str(dis_list))
    return index_vertex_point_tri_of_cluster,label_cluster_charger


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
        # plt.title(f"Estimated number of clusters: {n_clusters_}")
        ### plt.show()
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
        plot_check_cluster(current_file)
        if show_key == 1:
            plt.xlim([-1.5, 1.5])
            plt.ylim([-0.5,1.5])
            plt.title(f"current_file : {current_file}")
            plt.show()
        current_file += 1
        

    # print("num_dis_list"+str(len(dis_list)))
    # print(dis_list)
    # for i in range(len(dis_list)):
    #     if dis_list[i].find(200):
    #         print("error : file "+str(i)+"cannot find charger")
    #     if dis_list[i][0].find(200):
    #         print("error : file "+str(i)+"charger more than 1")

    
# print()
if __name__ == '__main__':
    main()

    # plt.legend()
    # plt.show()