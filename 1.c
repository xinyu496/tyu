case(P_Scan):
		{
			LeadData.fwscan_start_V = LeadData.speed_auto;//3;				//方位速度
//			LeadData.fyscan_start_step = visible_data;
			
			//扫描参数初始化  只执行一次的内容
			if(LeadData.Scan_Init == 1)
			{
				  logic_reset = 1;
					LeadData.Scan_Init = 0;
					LeadData.fwscan_start_V = LeadData.speed_auto;//3;				//方位速度
					if((LeadData.Scan_Switch == 4) || (LeadData.Scan_Switch == 5) || (LeadData.Scan_Switch == 6))
					{
						if(visible_data > 2.5)
						{
							LeadData.fyscan_start_step =  0;
						}
//						else if(visible_data < 1)
//						{
//							LeadData.fyscan_start_step = 1;
//						}
						else
						{
							LeadData.fyscan_start_step =  visible_data*0.8;	//俯仰步进角,重叠20%
						}
					}
					else if((LeadData.Scan_Switch == 7) || (LeadData.Scan_Switch == 8) || (LeadData.Scan_Switch == 9))
					{
						if(visible_data > 5)
						{
							LeadData.fyscan_start_step = 0;
						}
//						else if(visible_data < 1)
//						{
//							LeadData.fyscan_start_step = 1;
//						}
						else
						{
							LeadData.fyscan_start_step = visible_data*0.8;	//俯仰步进角,重叠20%
						}
					}
					Scan_Ready_Flag = 0;		//重新开始
					LeadData.HG_Scan_limit = 0;		//扫描限位提示清零
					
			//**************************************参数加载********************************//
//				if(visible_data < 1)
//				{
//					visible_data = 1;
//				}
				if(LeadData.Scan_Switch == 4)   //搜索范围10*5
				{			
					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle, (10-visible_data)*0.5 );
					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,2.5 );// / visible_data);			 
				}
				else if(LeadData.Scan_Switch == 5)	//搜索范围20*5
				{
					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle, (20-visible_data)*0.5 );
					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,2.5 );// / visible_data);			 		 
				}
				else if(LeadData.Scan_Switch == 6)	//搜索范围30*5
				{
					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle, (30-visible_data)*0.5 );
					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,2.5);// / visible_data);			 			 
				}
				else if(LeadData.Scan_Switch == 7)	//搜索范围10*10
				{
					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle, (10-visible_data)*0.5 );
					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,5 );// / visible_data);			 			 
				}
				else if(LeadData.Scan_Switch == 8)	//搜索范围20*10
				{
					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle, (20-visible_data)*0.5 );
					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,5);// / visible_data);			 		
				}
				else if(LeadData.Scan_Switch == 9)	//搜索范围30*10
				{
					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle, (30-visible_data)*0.5 );
					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,5);// / visible_data);			 		
				}
				//计算边界
				LeadData.fwscan_Llimt = LeadData.fwscan_center - LeadData.WFW_Scan_Single_Bound;
				LeadData.fwscan_Rlimt = LeadData.fwscan_center + LeadData.WFW_Scan_Single_Bound;

				LeadData.fyscan_downlimt = LeadData.fyscan_center - LeadData.WGD_Scan_Single_Bound;
				LeadData.fyscan_uplimt   = LeadData.fyscan_center + LeadData.WGD_Scan_Single_Bound;
		//**************************************参数加载完毕********************************//
			}
//			if(LeadData.Scan_Init == 1)
//			{
//					LeadData.Scan_Init = 0;
//			
//					Scan_Ready_Flag = 0;		//重新开始
//					LeadData.HG_Scan_limit = 0;		//扫描限位提示清零
//					
//			//**************************************参数加载********************************//
//				if(LeadData.Scan_Switch == 3)   //搜索范围10*5
//				{			
//					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle,5);
//					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,2.5);			 
//				}
//				else if(LeadData.Scan_Switch == 4)	//搜索范围20*5
//				{
//					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle,10);
//					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,2.5);			 		 
//				}
//				else if(LeadData.Scan_Switch == 5)	//搜索范围30*5
//				{
//					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle,15);
//					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,2.5);			 			 
//				}
//				else if(LeadData.Scan_Switch == 6)	//搜索范围10*10
//				{
//					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle,5);
//					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,5);			 			 
//				}
//				else if(LeadData.Scan_Switch == 7)	//搜索范围20*10
//				{
//					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle,10);
//					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,5);			 		
//				}
//				else if(LeadData.Scan_Switch == 8)	//搜索范围30*10
//				{
//					LeadData.WFW_Scan_Single_Bound = WFW_Scan_Bound_Calculate(LeadData.Now_FWAngle,15);
//					LeadData.WGD_Scan_Single_Bound = WGD_Scan_Bound_Calculate(LeadData.Now_FYAngle,5);			 		
//				}
//				//计算边界
//				LeadData.fwscan_Llimt = LeadData.fwscan_center - LeadData.WFW_Scan_Single_Bound;
//				LeadData.fwscan_Rlimt = LeadData.fwscan_center + LeadData.WFW_Scan_Single_Bound;

//				LeadData.fyscan_downlimt = LeadData.fyscan_center - LeadData.WGD_Scan_Single_Bound;
//				LeadData.fyscan_uplimt   = LeadData.fyscan_center + LeadData.WGD_Scan_Single_Bound;
//		//**************************************参数加载完毕********************************//
//			}
				
		//**************************************伺服执行********************************//
			if((FeedBack.WHG_LockState == 0)&&(FeedBack.NK_LockState == 0))		//松脱	 
			{	
				//先到达起始位置
			 if(Scan_Ready_Flag == 0)
			 {
					clr_fw_g();
					clr_fw_v();
					clr_fw_a();
					clr_fwdg();
					
					clr_gd_g();
					clr_gd_a();
					clr_gd_v();
					clr_gddg();
					
					clr_wgd_f();
					clr_wgd_v();    
					 
					clr_wfw_f();
					clr_wfw_v();	

					clr_gddg();
					clr_fwdg();	

					clr_gd_t_1();
					clr_fw_t_1();
					
					//坐标变换
					ae_to_rp(LeadData.fwscan_center,LeadData.fyscan_center,User_Quat.R_fb,&User_Quat.R_give,&User_Quat.P_give);  
					LeadData.Scan_start_HG = User_Quat.R_give;
					LeadData.Scan_start_FY = User_Quat.P_give;
		  
		  
					GDControl.P_give = 0;
					GDControl.Ev_give = gdploop(GDControl.Kp_P,GDControl.Ki_P,GDControl.SamT,GDSensor.Uplmt,GDSensor.Dwnlmt,GDControl.bound_P,GDControl.Ev_Set,GDControl.Evmax,GDControl.P_give,GDControl.P_fb,gdp_deadzone);		 
					GDControl.I_give = -1.0*gdevloop(GDControl.Kp_Ev,GDControl.Ki_Ev,GDControl.SamT,GDControl.Imax,GDControl.Ev_give,GDControl.Ev_fb);
					gd_en();

					FWControl.P_give = 0;
					FWControl.Ev_give = fwploop(FWControl.Kp_P,FWControl.Ki_P,FWControl.SamT,FWSensor.Llmt,FWSensor.Rlmt,FWControl.bound_P,FWControl.Ev_Set,FWControl.Evmax,FWControl.P_give,FWControl.P_fb,0);
					FWControl.I_give = fwevloop(FWControl.Kp_Ev,FWControl.Ki_Ev,FWControl.SamT,FWControl.Imax,FWControl.Ev_give,FWControl.Ev_fb);
					fw_en();
					
					WGDControl.P_give = LeadData.Scan_start_FY;  //P:代表框架俯仰
					WGDControl.Ev_give = wgdploop(WGDControl.Kp_P,WGDControl.Ki_P,WGDControl.SamT,WGDSensor.Uplmt,WGDSensor.Dwnlmt,WGDControl.bound_P,WGDControl.Ev_Set,WGDControl.Evmax,WGDControl.P_give,WGDControl.P_fb,wgdp_deadzone);
					WGDControl.I_give = wgdevloop(WGDControl.Kp_Ev,WGDControl.Ki_Ev,WGDControl.SamT,WGDControl.Imax,WGDControl.Ev_give,WGDControl.Ev_fb,wgdp_deadzone);			 
					wgd_en();
					
					WFWControl.P_give = LeadData.Scan_start_HG;	//R:代表框架横滚
					WFWControl.Ev_give = wfwploop(WFWControl.Kp_P,WFWControl.Ki_P,WFWControl.SamT,WFWSensor.Llmt,WFWSensor.Rlmt,WFWControl.bound_P,WFWControl.Ev_Set,WFWControl.Evmax,WFWControl.P_give,WFWControl.P_fb,0);
					WFWControl.I_give =  wfwevloop(WFWControl.Kp_Ev,WFWControl.Ki_Ev,WFWControl.SamT,WFWControl.Imax,WFWControl.Ev_give,WFWControl.Ev_fb);			 
					wfw_en();	
					
					//判断到位
					static uint8_t cnt = 0;

					if(fabs(WFWControl.P_err)<0.5)
					{
						if(fabs(WGDControl.P_err)<0.5)
						{
							cnt++;
						}
						else
						{
							cnt = 0;
						}
					}
					else
					{
						cnt = 0;
					}
					if(cnt>20)
					{					
						Scan_Ready_Flag = 1;    //到达起始位置
						
						User_Quat.A_V_give = LeadData.fwscan_start_V;
						FY_scan_dir = 1;
						
						LeadData.Scan_Vloop = 1;
						LeadData.Scan_Ploop = 0;
						
						cnt = 0;
					}		
				}
				else if(Scan_Ready_Flag == 1)
				{
						SF_Mode = 0x06;

						clr_fw_g();
						clr_fw_ea();	
					 
						clr_gd_g();
						clr_gd_ea();	
						
						clr_wgd_v();

						clr_gddg();
						clr_fwdg();	

						clr_gd_t_1();
						clr_fw_t_1();
						
						if((LeadData.Scan_Vloop == 1) && (LeadData.Scan_Ploop == 0))		//扫描动作
						{
								if(LeadData.fwscan_Llimt == LeadData.fwscan_Rlimt)    //zuoyou限位xiangdeng
								{
									User_Quat.A_V_give = 0;
									LeadData.HG_Scan_limit = 1;
								}
								else
								{
									logic_lhhsb3();//自动扫描状态机
								}
								
								//俯仰方向速度	
								User_Quat.E_V_give = 0;
								
								//坐标转换								
								velocity_ae_to_rp(User_Quat.R_fb,User_Quat.P_fb,User_Quat.A_V_give,User_Quat.E_V_give,&User_Quat.R_V_give,&User_Quat.P_V_give);		

								/**********限幅，边界处理************/
								//横滚
								if(fabs(User_Quat.R_fb) >= 160)	
								{
									LeadData.fwscan_V = 0;
								}
								else					
								{	
									if(User_Quat.R_V_give > 200)
										LeadData.fwscan_V = 200;
									else if(User_Quat.R_V_give < -200)
										LeadData.fwscan_V = -200;
									else
										LeadData.fwscan_V = User_Quat.R_V_give;
								}
								//俯仰
								if(fabs(User_Quat.P_fb) >= 89)		
								{								
									LeadData.fyscan_V = 0;
								}
								else						
								{							
									if(User_Quat.P_V_give > 120)
										LeadData.fyscan_V = 120;
									else if(User_Quat.P_V_give < -120)
										LeadData.fyscan_V = -120;
									else
										LeadData.fyscan_V = User_Quat.P_V_give;
								}
								/**********end************/
								
								
								//伺服动作执行
								GDControl.V_give = LeadData.fyscan_V;
								GDControl.A_give = gdvloop(GDControl.Kp_V,GDControl.Ki_V,GDControl.SamT,GDControl.Amax,GDSensor.Uplmt,GDSensor.Dwnlmt,GDControl.V_give,GDControl.V_fb,GDControl.P_fb,WGDSensor.Uplmt_vloop,WGDSensor.Dwnlmt_vloop,WGDControl.P_fb,Axis2_or_not);
								GDControl.I_give = -1.0*gdaloop(GDControl.Kp_A,GDControl.Ki_A,GDControl.SamT,GDControl.Kg_A,GDControl.BW_A,1,GDControl.Imax,GDControl.A_give,GDControl.A_fb);
								gd_en();
								WGDControl.Ev_give = wgdfloop(WGDControl.Kp_F,WGDControl.Ki_F,0.001,31,GDControl.P_fb,GDControl.Ev_fb,WGDControl.Cmp_ratio);
								WGDControl.I_give = wgdevloop(WGDControl.Kp_Ev,WGDControl.Ki_Ev,WGDControl.SamT,WGDControl.Imax,WGDControl.Ev_give,WGDControl.Ev_fb,wgdp_deadzone);			 
								wgd_en();
								
//								if(fabs(WGDControl.P_fb) < 5-0.1)
//								{
//									FWControl.P_give = 0;
//									FWControl.Ev_give = fwploop(FWControl.Kp_P,FWControl.Ki_P,FWControl.SamT,FWSensor.Llmt,FWSensor.Rlmt,FWControl.bound_P,FWControl.Ev_Set,FWControl.Evmax,FWControl.P_give,FWControl.P_fb,0);
//									FWControl.I_give = fwevloop(FWControl.Kp_Ev,FWControl.Ki_Ev,FWControl.SamT,FWControl.Imax,FWControl.Ev_give,FWControl.Ev_fb);
//									fw_en();
//									
//									WFWControl.Ev_give = LeadData.fwscan_V;
//									WFWControl.I_give =  wfwevloop(WFWControl.Kp_Ev,WFWControl.Ki_Ev,WFWControl.SamT,WFWControl.Imax,WFWControl.Ev_give,WFWControl.Ev_fb);			 
//									wfw_en();	
//								}
//								else if(fabs(WGDControl.P_fb) > 5+0.1)
//								{
									FWControl.V_give = LeadData.fwscan_V * WGDSensor.Cos_WGD;   //LeadData.fwscan_V是横滚速度
									FWControl.A_give = fwvloop(FWControl.Kp_V,FWControl.Ki_V,FWControl.SamT,FWControl.Amax,FWSensor.Llmt,FWSensor.Rlmt,FWControl.V_give,FWControl.V_fb,FWControl.P_fb,GDangle_real,FWControl.bound_A,WFWSensor.Llmt,WFWSensor.Rlmt,WFWControl.P_fb,Axis2_or_not);
									FWControl.I_give = fwaloop(FWControl.Kp_A,FWControl.Ki_A,FWControl.SamT,FWControl.Kg_A,FWControl.BW_A,fabs(cos(WFWControl.P_fb)),FWControl.Imax,FWControl.A_give,FWControl.A_fb,GDangle_real,FWControl.bound_A);
									fw_en();
									WFWControl.V_give = LeadData.fwscan_V;
									WFWControl.I_give = wfwvloop(WFWControl.Kp_V,WFWControl.Ki_V,WFWControl.Kp_V_C,WFWControl.Ki_V_C,WFWControl.SamT,WFWControl.Imax,WFWSensor.Llmt,WFWSensor.Rlmt,WFWControl.V_give,WFWControl.V_fb,FWControl.Vmax,WFWControl.P_fb,WGDControl.P_fb,FWControl.P_fb,WGDSensor.Sec_WGD,1,5);
									wfw_en();		
//								}
		
						}
						else if((LeadData.Scan_Vloop == 0) && (LeadData.Scan_Ploop == 1))			//步进动作
						{
//							//对步进角进行限幅
//							if(LeadData.fyscan_start_step >= 5)			//防止视场过大，步进超出搜索范围
//								LeadData.fyscan_step_lim = 4;
//							if(LeadData.fyscan_step < LeadData.WGD_Scan_Single_Bound)	//步进角太大，步进超出限位
//								LeadData.fyscan_step_lim = LeadData.WGD_Scan_Single_Bound;
//							else
//								LeadData.fyscan_step_lim = LeadData.fyscan_start_step;
							
							//对角度赋值
							User_Quat.A_give = LeadData.Scan_Switch_FW;
							User_Quat.E_give = LeadData.Scan_Switch_FY + FY_scan_dir * LeadData.fyscan_start_step;
							//限幅
							if(User_Quat.A_give >= 90) User_Quat.A_give = 90;
							else if(User_Quat.A_give <= -90) User_Quat.A_give = -90;
							if(User_Quat.E_give >= 90) User_Quat.E_give = 90;
							else if(User_Quat.E_give <= -90) User_Quat.E_give = -90;
							
							
							//换向
							if(LeadData.fyscan_downlimt == LeadData.fyscan_uplimt)
							{
								FY_scan_dir = 0;
							}
							else
							{
								if(User_Quat.E_give <= LeadData.fyscan_downlimt)
									FY_scan_dir = 1;
								else if(User_Quat.E_give >= LeadData.fyscan_uplimt)
									FY_scan_dir = -1; 
							}
							
							//坐标转换
							ae_to_rp(User_Quat.A_give,User_Quat.E_give,User_Quat.R_fb,&User_Quat.R_give,&User_Quat.P_give);  
							
							//实际给定运动角度
							LeadData.fwscan_step = User_Quat.R_give;
							LeadData.fyscan_step = User_Quat.P_give;
							
							//伺服动作执行
							GDControl.P_give = 0;
							GDControl.Ev_give = gdploop(GDControl.Kp_P,GDControl.Ki_P,GDControl.SamT,GDSensor.Uplmt,GDSensor.Dwnlmt,GDControl.bound_P,GDControl.Ev_Set,GDControl.Evmax,GDControl.P_give,GDControl.P_fb,gdp_deadzone);		 
							GDControl.I_give = -1.0*gdevloop(GDControl.Kp_Ev,GDControl.Ki_Ev,GDControl.SamT,GDControl.Imax,GDControl.Ev_give,GDControl.Ev_fb);
							gd_en();

							FWControl.P_give = 0;
							FWControl.Ev_give = fwploop(FWControl.Kp_P,FWControl.Ki_P,FWControl.SamT,FWSensor.Llmt,FWSensor.Rlmt,FWControl.bound_P,FWControl.Ev_Set,FWControl.Evmax,FWControl.P_give,FWControl.P_fb,0);
							FWControl.I_give = fwevloop(FWControl.Kp_Ev,FWControl.Ki_Ev,FWControl.SamT,FWControl.Imax,FWControl.Ev_give,FWControl.Ev_fb);
							fw_en();
							
							WGDControl.P_give = LeadData.fyscan_step;
							WGDControl.Ev_give = wgdploop(WGDControl.Kp_P,WGDControl.Ki_P,WGDControl.SamT,WGDSensor.Uplmt,WGDSensor.Dwnlmt,WGDControl.bound_P,WGDControl.Ev_Set,WGDControl.Evmax,WGDControl.P_give,WGDControl.P_fb,wgdp_deadzone);
							WGDControl.I_give = wgdevloop(WGDControl.Kp_Ev,WGDControl.Ki_Ev,WGDControl.SamT,WGDControl.Imax,WGDControl.Ev_give,WGDControl.Ev_fb,wgdp_deadzone);			 
							wgd_en();
							
							WFWControl.P_give = LeadData.fwscan_step;
							WFWControl.Ev_give = wfwploop(WFWControl.Kp_P,WFWControl.Ki_P,WFWControl.SamT,WFWSensor.Llmt,WFWSensor.Rlmt,WFWControl.bound_P,WFWControl.Ev_Set,WFWControl.Evmax,WFWControl.P_give,WFWControl.P_fb,0);
							WFWControl.I_give =  wfwevloop(WFWControl.Kp_Ev,WFWControl.Ki_Ev,WFWControl.SamT,WFWControl.Imax,WFWControl.Ev_give,WFWControl.Ev_fb);			 
							wfw_en();	
							
								//判断到位切换控制环
								static uint8_t cnt = 0;

								if(fabs(WFWControl.P_err)<0.05)
								{
									if(fabs(WGDControl.P_err)<0.05)
									{
										cnt++;
									}
									else
									{
										cnt = 0;
									}
								}
								else
								{
									cnt = 0;
								}
								if(cnt>20)
								{					
									LeadData.Scan_Vloop = 1;
									LeadData.Scan_Ploop = 0;
									
									cnt = 0;
								}		
						}

				}

			 }
			else
			{
			  clr_all();
			  all_brake();
			} 
		 break;  
		}