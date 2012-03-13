FILE* open_text_file_for_output(char *outfile);
double average_real_part_of_trace_of_rectangle_path(quad_su3 *conf,int mu,int nu,int nstep_mu,int nstep_nu,su3 *u);
double calculate_weighted_residue_stD2ee(color *source,color *sol,quad_su3 **conf,double m2,color *s,color *t,int dinf);
double calculate_weighted_residue_tmQ2_RL(spincolor *source,spincolor *sol,quad_su3 *conf,double kappa,double m,spincolor *s,spincolor *t,int dinf,int RL);
double compute_landau_or_coulomb_gauge_fixing_quality(quad_su3 *conf,int nmu);
double global_plaquette_eo_conf(quad_su3 *ev_conf,quad_su3 *od_conf);
double global_plaquette_lx_conf(quad_su3 *conf);
double global_plaquette_variance_lx_conf(quad_su3 *conf);
double lfact(double n);
double max_double(double a,double b);
double min_double(double a,double b);
double real_part_of_trace_su3_prod_su3_dag(su3 a,su3 b);
double rnd_get_gauss(rnd_gen *gen,double ave,double sig);
double rnd_get_unif(rnd_gen *gen,double min,double max);
double sqr(double a);
double squared_complex_norm(complex c);
double su3_normq(su3 U);
double take_time();
int bitrev(int in,int l2n);
int bordlx_of_coord(int *x,int mu);
int bordlx_of_coord_list(int x0,int x1,int x2,int x3,int mu);
int bulk_recip_lat_volume(int *P,int *L);
int bulk_volume(int *L);
int check_cgmm2s_residue_stD2ee(int *run_flag,double *residue_mass,int nrun,double rr,double *zfs,int st_crit,double st_res,double st_res2,int iter,color **sol,int nmass,double *m2,color *source,quad_su3 **conf,color *s,color *t,double source_norm);
int check_cgmms_residue_tmQ2_RL(int *run_flag,double *residue_mass,int nrun,double rr,double *zfs,int st_crit,double st_res,double st_res2,int iter,spincolor **sol,int nmass,double *m,spincolor *source,quad_su3 *conf,double kappa,spincolor *s,spincolor *t,double source_norm,int RL);
int compute_border_variance(int *L,int *X,int consider_reciprocal);
int compute_nissa_vect_memory_usage();
int create_dir(char *path);
int dir_exists(char *path);
int edgelx_of_coord(int *x,int mu,int nu);
int factorize(int *list,int N);
int file_exists(const char *path);
int find_max_pow2(int a);
int glblx_of_coord(coords x);
int glblx_of_coord_list(int x0,int x1,int x2,int x3);
int loclx_of_coord(coords x);
int loclx_of_coord_list(int x0,int x1,int x2,int x3);
int log2N(int N);
int lx_of_coord(coords x,coords s);
int main();
int master_fprintf(FILE *stream,const char *format,...);
int max_int(int a,int b);
int min_int(int a,int b);
int nissa_reader_search_record(nissa_reader *reader,const char *expected_record);
int rank_hosting_site_of_coord(coords x);
int rank_of_coord(coords x);
int read_binary_blob(void *out,char *path,const char *expected_record,int nmax_bytes_per_site);
int rnd_get_pm_one(rnd_gen *gen);
nissa_reader **start_reading_colorspinspin(colorspinspin *out,char *base_path,char *end_path);
nissa_reader *nissa_reader_create();
nissa_reader *nissa_reader_start_reading(void *out,char *filename,const char *record_name,int max_bytes_per_site);
nissa_reader *start_reading_color(color *out,char *path);
nissa_reader *start_reading_gauge_conf(quad_su3 *out,char *path);
nissa_reader *start_reading_real_vector(double *out,char *path,const char *expected_record,int nreals_per_site);
nissa_reader *start_reading_spincolor(spincolor *out,char *path);
uint32_t ildg_crc32(uint32_t crc,const unsigned char *buf,size_t len);
uint32_t ildg_crc32_fix_endianess(uint32_t crc,const unsigned char *buf,size_t len);
void *nissa_true_malloc(const char *tag,int nel,int size_per_el,const char *type,const char *file,int line);
void Momentum(int **iP,double *bc,double *P2,double *SinP2,double **P,double **SinP,double *SinP4,int nmom);
void Pline(su3 *Pline,quad_su3 *conf);
void Pline_backward(su3 *Pline, quad_su3 *conf);
void Pline_forward(su3 *Pline, quad_su3 *conf);
void Pmunu_term(as2t_su3 *Pmunu,quad_su3 *conf);
void ac_rotate_gauge_conf(quad_su3 *out,quad_su3 *in,int axis);
void ac_rotate_vector(char *out,char *in,int axis,int bps);
void adapt_theta(quad_su3 *conf,double *old_theta,double *put_theta,int putonbords,int putonedges);
void addrem_stagphases_to_eo_conf(quad_su3 **eo_conf);
void ape_spatial_smear_conf(quad_su3 *smear_conf,quad_su3 *origi_conf,double alpha,int nstep);
void apply_st2Deo(color *out,quad_su3 **conf,color *in);
void apply_st2Doe(color *out,quad_su3 **conf,color *in);
void apply_stD2ee(color *out,quad_su3 **conf,color *temp,double mass,color *in);
void apply_stDoe(color *out,quad_su3 **conf,color *in);
void apply_tmQ(spincolor *out,spincolor *in,quad_su3 *conf,double kappac,double mu);
void apply_tmQ2(spincolor *out,spincolor *in,quad_su3 *conf,double kappa,double mu,spincolor *temp);
void apply_tmQ2_RL(spincolor *out,spincolor *in,quad_su3 *conf,double kappa,double mu,spincolor *temp,int RL);
void apply_tmQ2_left(spincolor *out,spincolor *in,quad_su3 *conf,double kappa,double mu,spincolor *temp);
void apply_tmQ_RL(spincolor *out,spincolor *in,quad_su3 *conf,double kappa,double mu,int RL);
void apply_tmQ_left(spincolor *out,spincolor *in,quad_su3 *conf,double kappac,double mu);
void apply_tmQ_v1(spincolor *out,spincolor *in,quad_su3 *conf,double kappac,double mu);
void as2t_saturate(complex out,as2t a,as2t b);
void as2t_su3_put_to_zero(as2t_su3 m);
void assign_complex_prod_i(complex a);
void assign_complex_prod_minus_i(complex a);
void average_list_of_gathered_vector_sites(double *vec,int *sites,int nsites,int dps);
void average_trace_of_rectangle_path(complex tra,quad_su3 *conf,int mu,int nu,int nstep_mu,int nstep_nu,su3 *u);
void check_borders_allocated(void *v);
void check_edges_allocated(void *v);
void check_endianess();
void check_minimal_allocated_size(void *v,int l,const char *err_mess);
void checksum_compute_ildg_data(uint32_t *check,void *data,size_t bps);
void checksum_compute_nissa_data(uint32_t *check,void *data,size_t bps);
void close_input();
void close_nissa();
void color_copy(color b,color a);
void color_isubt(color a,color b,color c);
void color_isubtassign(color a,color b);
void color_isumm(color a,color b,color c);
void color_isummassign(color a,color b);
void color_print(color c);
void color_prod_double(color a,color b,double c);
void color_put_to_gauss(color H,rnd_gen *gen,double sigma);
void color_put_to_zero(color m);
void color_subt(color a,color b,color c);
void color_subtassign(color a,color b);
void color_summ(color a,color b,color c);
void color_summassign(color a,color b);
void communicate_eo_borders(char *ev_data,char *od_data,MPI_Datatype *MPI_EO_BORD_SEND_TXY,MPI_Datatype *MPI_EV_BORD_SEND_Z,MPI_Datatype *MPI_OD_BORD_SEND_Z,MPI_Datatype *MPI_EO_BORD_RECE,int nbytes_per_site);
void communicate_eo_color_borders(color *ev,color *od);
void communicate_eo_gauge_borders(quad_su3 *ev_conf,quad_su3 *od_conf);
void communicate_ev_borders(char *ev_data,MPI_Datatype *MPI_EV_BORD_SEND_TXY,MPI_Datatype *MPI_EV_BORD_SEND_Z,MPI_Datatype *MPI_EV_BORD_RECE,int nbytes_per_site);
void communicate_ev_color_borders(color *ev);
void communicate_ev_spincolor_borders(spincolor *ev);
void communicate_lx_borders(char *data,MPI_Datatype *MPI_BORD_SEND,MPI_Datatype *MPI_BORD_RECE,int nbytes_per_site);
void communicate_lx_edges(char *data,MPI_Datatype *MPI_EDGE_SEND,MPI_Datatype *MPI_EDGE_RECE,int nbytes_per_site);
void communicate_lx_gauge_borders(quad_su3 *conf);
void communicate_lx_gauge_edges(quad_su3 *conf);
void communicate_lx_spincolor_borders(spincolor *s);
void communicate_lx_su3_borders(su3 *u);
void communicate_lx_su3_edges(su3 *u);
void communicate_od_borders(char *od_data,MPI_Datatype *MPI_EV_BORD_SEND_TXY,MPI_Datatype *MPI_OD_BORD_SEND_Z,MPI_Datatype *MPI_EV_BORD_RECE,int nbytes_per_site);
void communicate_od_color_borders(color *od);
void communicate_od_spincolor_borders(spincolor *od);
void comp_get_rnd(complex out,rnd_gen *gen,enum rnd_type rtype);
void complex_conj(complex a,complex b);
void complex_copy(complex a,complex b);
void complex_minus_conj(complex a,complex b);
void complex_pow(complex res,complex base,double exp);
void complex_prod_double(complex a,complex b,double c);
void complex_prodassign_double(complex a,double c);
void complex_reciprocal(complex rec,complex c);
void complex_sqrt(complex res,complex base);
void complex_subt(complex a,complex b,complex c);
void complex_subt_conj1(complex a,complex b,complex c);
void complex_subt_conj2(complex a,complex b,complex c);
void complex_subt_the_conj1_prod(complex a,complex b,complex c);
void complex_subt_the_conj1_prod_i(complex a,complex b,complex c);
void complex_subt_the_conj2_prod(complex a,complex b,complex c);
void complex_subt_the_conj2_prod_i(complex a,complex b,complex c);
void complex_subt_the_conj_conj_prod(complex a,complex b,complex c);
void complex_subt_the_conj_conj_prod_i(complex a,complex b,complex c);
void complex_subt_the_prod(complex a,complex b,complex c);
void complex_subt_the_prod_double(complex a,complex b,double c);
void complex_subt_the_prod_i(complex a,complex b,complex c);
void complex_subt_the_prod_idouble(complex a,complex b,double c);
void complex_subtassign(complex a,complex b);
void complex_summ(complex a,complex b,complex c);
void complex_summ_conj1(complex a,complex b,complex c);
void complex_summ_conj2(complex a,complex b,complex c);
void complex_summ_the_conj1_prod(complex a,complex b,complex c);
void complex_summ_the_conj1_prod_i(complex a,complex b,complex c);
void complex_summ_the_conj2_prod(complex a,complex b,complex c);
void complex_summ_the_conj2_prod_i(complex a,complex b,complex c);
void complex_summ_the_conj_conj_prod(complex a,complex b,complex c);
void complex_summ_the_conj_conj_prod_i(complex a,complex b,complex c);
void complex_summ_the_prod(complex a,complex b,complex c);
void complex_summ_the_prod_double(complex a,complex b,double c);
void complex_summ_the_prod_i(complex a,complex b,complex c);
void complex_summ_the_prod_idouble(complex a,complex b,double c);
void complex_summassign(complex a,complex b);
void compute_landau_or_coulomb_delta(su3 g,quad_su3 *conf,int ivol,int nmu);
void compute_landau_or_coulomb_quality_delta(su3 g,quad_su3 *conf,int ivol,int nmu);
void compute_point_staples_eo_conf(quad_su3 staple,quad_su3 **eo_conf,int A);
void compute_su3spinspin_propagators_multi_mass(su3spinspin ***prop,su3spinspin *source,quad_su3 *conf,double kappa,double *mass,int nmass,int niter_max,double stopping_residue,double minimal_residue,int stopping_criterion);
void coulomb_gauge_fix(quad_su3 *conf_out,quad_su3 *conf_in,double precision);
void data_coordinate_order_shift(complex *data,int ncpp,int mu0);
void density_profile(double *glb_rho,spincolor *sp,int *or_pos);
void dirac_prod(dirac_matr *out,dirac_matr *in1,dirac_matr *in2);
void dirac_summ(dirac_matr *out,dirac_matr *in1,dirac_matr *in2);
void doubles_to_doubles_changing_endianess(double *dest,double *sour,int ndoubles);
void doubles_to_floats_changing_endianess(float *dest,double *sour,int n);
void doubles_to_floats_same_endianess(float *dest,double *sour,int n);
void expect_str(const char *exp_str);
void exponentiate(su3 g,su3 a);
void fft1d(complex *out,complex *in,int ncpp,int mu,double sign,int normalize);
void fft4d(complex *out,complex *in,int ncpp,double sign,int normalize);
void file_touch(const char *path);
void finalize_reading_color(color *c,nissa_reader *reader);
void finalize_reading_colorspinspin(colorspinspin *css,nissa_reader **reader);
void finalize_reading_gauge_conf(quad_su3 *conf,nissa_reader *reader);
void finalize_reading_real_vector(double *out,nissa_reader *reader,int nreals_per_site);
void finalize_reading_spincolor(spincolor *sc,nissa_reader *reader);
void find_landau_or_coulomb_gauge_fixing_matr(su3 *fixm,quad_su3 *conf,double required_precision,int nmu);
void find_local_landau_or_coulomb_gauge_fixing_transformation(su3 g,quad_su3 *conf,int ivol,int nmu);
void find_minimal_surface_grid(int *mP,int *L,int NP);
void find_temporal_gauge_fixing_matr(su3 *fixm,quad_su3 *u);
void floats_to_doubles_changing_endianess(double *dest,float *sour,int n);
void floats_to_doubles_same_endianess(double *dest,float *sour,int n);
void floats_to_floats_changing_endianess(float *dest,float *sour,int nint);
void fprintf_friendly_filesize(FILE *fout,int quant);
void fprintf_friendly_units(FILE *fout,int quant,int orders,const char *units);
void gathered_vector_cubic_symmetrize(double *vec,int dps);
void gathered_vector_mirrorize(double *vec,int dps);
void gauge_transform_conf(quad_su3 *uout,su3 *g,quad_su3 *uin);
void generate_delta_source(su3spinspin *source,int *x);
void generate_spindiluted_source(colorspinspin *source,enum rnd_type rtype,int twall);
void generate_undiluted_source(spincolor *source,enum rnd_type rtype,int twall);
void get_loclx_and_rank_of_coord(int *loc_site,int *rank,coords g);
void get_spincolor_from_colorspinspin(spincolor out,colorspinspin in,int id_source);
void get_spincolor_from_su3spinspin(spincolor out,su3spinspin in,int id_source,int ic_source);
void herm_put_to_gauss(su3 H,rnd_gen *gen,double sigma);
void hyp_smear_conf(quad_su3 *sm_conf,quad_su3 *conf,double alpha0,double alpha1,double alpha2);
void hyp_smear_conf_dir(quad_su3 *sm_conf,quad_su3 *conf,double alpha0,double alpha1,double alpha2,int req_mu);
void init_base_gamma();
void init_dirac(dirac_matr *out,int pos0,double rea0,double ima0,int pos1,double rea1,double ima1,int pos2,double rea2,double ima2,int pos3,double rea3,double ima3);
void init_grid(int T,int L);
void init_nissa();
void initialize_eo_bord_receivers_of_kind(MPI_Datatype *MPI_EO_BORD_RECE,MPI_Datatype *base);
void initialize_eo_bord_senders_of_kind(MPI_Datatype *MPI_EO_BORD_SEND_TXY,MPI_Datatype *MPI_EV_BORD_SEND_Z,MPI_Datatype *MPI_OD_BORD_SEND_Z,MPI_Datatype *base);
void initialize_lx_bord_receivers_of_kind(MPI_Datatype *MPI_BORD_RECE,MPI_Datatype *base);
void initialize_lx_bord_senders_of_kind(MPI_Datatype *MPI_BORD_SEND,MPI_Datatype *base);
void initialize_lx_edge_receivers_of_kind(MPI_Datatype *MPI_EDGE_RECE,MPI_Datatype *base);
void initialize_lx_edge_senders_of_kind(MPI_Datatype *MPI_EDGE_SEND,MPI_Datatype *base);
void initialize_main_nissa_vect();
void internal_crash(int line,const char *file,const char *template,...);
void internal_decript_MPI_error(int line,const char *file,int rc,const char *template,...);
void inv_stD2ee_cgmm2s(color **sol,color *source,quad_su3 **conf,double *m2,int nmass,int niter,double st_res,double st_minres,int st_crit);
void inv_tmDQ_cgmms(spincolor **sol,spincolor *source,quad_su3 *conf,double kappa,double *m,int nmass,int niter,double st_res,double st_minres,int st_crit);
void inv_tmDQ_cgmms_RL(spincolor **sol,spincolor *source,quad_su3 *conf,double kappa,double *m,int nmass,int niter,double st_res,double st_minres,int st_crit,int RL);
void inv_tmDQ_cgmms_left(spincolor **sol,spincolor *source,quad_su3 *conf,double kappa,double *m,int nmass,int niter,double st_res,double st_minres,int st_crit);
void inv_tmD_cg_eoprec_eos(spincolor *solution_lx,spincolor *source_lx,spincolor *guess_Koo,quad_su3 *conf_lx,double kappa,double mu,int nitermax,double residue);
void inv_tmDee_or_oo_eos(spincolor *out,spincolor *in,double kappa,double mu);
void inv_tmDkern_eoprec_square_eos(spincolor *sol,spincolor *source,spincolor *guess,quad_su3 **conf,double kappa,double mu,int nitermax,double residue);
void inv_tmQ2_cg(spincolor *sol,spincolor *source,spincolor *guess,quad_su3 *conf,double kappa,double m,int niter,int rniter,double residue);
void inv_tmQ2_cg_RL(spincolor *sol,spincolor *source,spincolor *guess,quad_su3 *conf,double kappa,double m,int niter,int rniter,double residue,int RL);
void inv_tmQ2_cg_left(spincolor *sol,spincolor *source,spincolor *guess,quad_su3 *conf,double kappa,double m,int niter,int rniter,double residue);
void inv_tmQ2_cgmms(spincolor **sol,spincolor *source,quad_su3 *conf,double kappa,double *m,int nmass,int niter,double st_res,double st_minres,int st_crit);
void inv_tmQ2_cgmms_RL(spincolor **sol,spincolor *source,quad_su3 *conf,double kappa,double *m,int nmass,int niter,double st_res,double st_minres,int st_crit,int RL);
void inv_tmQ2_cgmms_left(spincolor **sol,spincolor *source,quad_su3 *conf,double kappa,double *m,int nmass,int niter,double st_res,double st_minres,int st_crit);
void jacobi_smearing(spincolor *smear_sc,spincolor *origi_sc,quad_su3 *conf,double kappa,int niter);
void landau_gauge_fix(quad_su3 *conf_out,quad_su3 *conf_in,double precision);
void landau_or_coulomb_gauge_fix(quad_su3 *conf_out,quad_su3 *conf_in,double precision,int nmu);
void last_nissa_vect_content_printf();
void local_gauge_transform(quad_su3 *conf,su3 g,int ivol);
void lot_of_mesonic_contractions(complex *glb_contr,int **op,int ncontr,colorspinspin **S0,colorspinspin **S1,intpair npr,intpair *pr_combo,int npr_combo,int twall);
void master_printf_box(const char *template,...);
void nissa_reader_close(nissa_reader *reader);
void nissa_reader_destroy(nissa_reader *reader);
void nissa_reader_finalize_reading(checksum read_check,nissa_reader *reader);
void nissa_reader_finalize_reading_current_record(nissa_reader *reader);
void nissa_reader_open(nissa_reader *reader,char *path);
void nissa_reader_start_reading_current_record(void *out,nissa_reader *reader,int max_nbytes_per_site);
void nissa_vect_content_fprintf(FILE *fout,nissa_vect *vect);
void nissa_vect_content_printf(nissa_vect *vect);
void open_input(char *input_path);
void overrelax(su3 out,su3 in,double w);
void paste_eo_parts_into_lx_spincolor(spincolor *out_lx,spincolor *in_ev,spincolor *in_od,int nsites);
void paste_eo_parts_into_lx_vector(char *out_lx,char *in_ev,char *in_od,int nsites,int bps);
void print_all_nissa_vect_content();
void print_backtrace_list();
void print_contraction_to_file(FILE *fout,int op1,int op2,complex *contr,int twall,const char *tag,double norm);
void print_contractions_to_file(FILE *fout,int ncontr,int *op1,int *op2,complex *contr,int twall,const char *tag,double norm);
void print_dirac(dirac_matr *in);
void print_spinspin(spinspin s);
void put_boundaries_conditions(quad_su3 *conf,double *theta_in_pi,int putonbords,int putonedges);
void put_spincolor_into_colorspinspin(colorspinspin out,spincolor in,int id_source);
void put_spincolor_into_su3spinspin(su3spinspin out,spincolor in,int id_source,int ic_source);
void quad_su3_copy(quad_su3 b,quad_su3 a);
void rank_coord_of_site_of_coord(coords rank_coord,coords glb_coord);
void read_checksum(checksum check_read,nissa_reader *reader);
void read_color(color *c,char *path);
void read_colorspinspin(colorspinspin *css,char *base_path,char *end_path);
void read_double(double *in);
void read_ildg_gauge_conf(quad_su3 *conf,char *path);
void read_ildg_gauge_conf_and_split_into_eo_parts(quad_su3 **eo_conf,char *path);
void read_int(int *in);
void read_list_of_doubles(char *tag,int *nentries,double **list);
void read_list_of_ints(char *tag,int *nentries,int **list);
void read_list_of_var(char *tag,int *nentries,char **list,int size_of_el,const char *par);
void read_real_vector(double *out,char *path,const char *expected_record,int nreals_per_site);
void read_spincolor(spincolor *sc,char *path);
void read_str(char *str,int length);
void read_str_double(const char *exp_str,double *in);
void read_str_int(const char *exp_str,int *in);
void read_str_str(const char *exp_str,char *in,int length);
void read_tm_colorspinspin_reconstructing(colorspinspin **css,char *base_path,char *end_path,quad_su3 *conf,double kappa,double mu);
void read_tm_spincolor_reconstructing(spincolor **out,spincolor *temp,char *path,quad_su3 *conf,double kappa,double mu);
void read_var(char *in,const char *par,int size_of);
void reconstruct_tm_doublet(spincolor *outminus,spincolor *outplus,spincolor *in,quad_su3 *conf,double kappac,double mu);
void rem_boundaries_conditions(quad_su3 *conf,double *theta_in_pi,int putonbords,int putonedges);
void remap_vector(char *out,char *in,coords *xto,coords *xfr,int bps);
void reorder_read_color(color *c);
void reorder_read_colorspinspin(colorspinspin *css);
void reorder_read_ildg_gauge_conf(quad_su3 *conf);
void reorder_read_spincolor(spincolor *sc);
void reorder_vector(char *vect,int *order,int nel,int sel);
void rnd_fill_pm_one_loc_vector(double *v,int nps);
void rnd_fill_unif_loc_vector(double *v,int dps,double min,double max);
void rnd_get_Z2(complex out,rnd_gen *gen);
void rnd_get_Z4(complex out,rnd_gen *gen);
void rnd_get_gauss_complex(complex out,rnd_gen *gen,complex ave,double sig);
void rotate_spinspin_to_physical_basis(spinspin s,int rsi,int rso);
void rotate_vol_colorspinspin_to_physical_basis(colorspinspin *s,int rsi,int rso);
void rotate_vol_su3spinspin_to_physical_basis(su3spinspin *s,int rsi,int rso);
void safe_color_prod_complex(color out,color in,complex factor);
void safe_color_prod_complex_conj(color out,color in,complex factor);
void safe_color_prod_su3(color a,color b,su3 c);
void safe_complex_conj1_prod(complex a,complex b,complex c);
void safe_complex_conj1_prod_minus(complex a,complex b,complex c);
void safe_complex_conj2_prod(complex a,complex b,complex c);
void safe_complex_conj2_prod_minus(complex a,complex b,complex c);
void safe_complex_prod(complex a,complex b,complex c);
void safe_complex_prod_i(complex a,complex b);
void safe_complex_prod_minus(complex a,complex b,complex c);
void safe_complex_prod_minus_i(complex a,complex b);
void safe_dirac_compl_prod(dirac_matr *out,dirac_matr *in,complex c);
void safe_dirac_prod_spincolor(spincolor out,dirac_matr *m,spincolor in);
void safe_spincolor_prod_complex(spincolor out,spincolor in,complex factor);
void safe_spincolor_prod_dirac(spincolor out,spincolor in,dirac_matr *m);
void safe_spincolor_summ_with_cfactor(spincolor a,spincolor b,spincolor c,complex factor);
void safe_spinspin_prod_dirac(spinspin out,spinspin in,dirac_matr *m);
void safe_su3_dag_prod_color(color a,su3 b,color c);
void safe_su3_dag_prod_su3(su3 a,su3 b,su3 c);
void safe_su3_dag_prod_su3_dag(su3 a,su3 b,su3 c);
void safe_su3_explicit_inverse(su3 invU,su3 U);
void safe_su3_hermitian(su3 out,su3 in);
void safe_su3_prod_color(color a,su3 b,color c);
void safe_su3_prod_complex(su3 a,su3 b,complex c);
void safe_su3_prod_conj_complex(su3 a,su3 b,complex c);
void safe_su3_prod_su3(su3 a,su3 b,su3 c);
void safe_su3_prod_su3_dag(su3 a,su3 b,su3 c);
void safe_su3spinspin_prod_complex(su3spinspin out,su3spinspin in,complex factor);
void set_eo_bord_senders_and_receivers(MPI_Datatype *MPI_EO_BORD_SEND_TXY,MPI_Datatype *MPI_EV_BORD_SEND_Z,MPI_Datatype *MPI_OD_BORD_SEND_Z,MPI_Datatype *MPI_EO_BORD_RECE,MPI_Datatype *base);
void set_eo_geometry();
void set_lx_bord_senders_and_receivers(MPI_Datatype *MPI_BORD_SEND,MPI_Datatype *MPI_BORD_RECE,MPI_Datatype *base);
void set_lx_edge_senders_and_receivers(MPI_Datatype *MPI_EDGE_SEND,MPI_Datatype *MPI_EDGE_RECE,MPI_Datatype *base);
void set_lx_geometry();
void site_trace_g_ccss_dag_g_ccss(complex c,dirac_matr *g1,su3spinspin s1,dirac_matr *g2,su3spinspin s2);
void site_trace_g_sdag_g_s(complex c,dirac_matr *g1,spinspin s1,dirac_matr *g2,spinspin s2);
void site_trace_g_sdag_g_s_g_sdag_g_s(complex c,dirac_matr *g1,spinspin s1,dirac_matr *g2,spinspin s2, dirac_matr *g3,spinspin s3,dirac_matr *g4,spinspin s4);
void smearing_apply_kappa_H(spincolor *H,double kappa,quad_su3 *conf,spincolor *smear_sc);
void spincolor_FT(spincolor *S,spincolor *FT,double *theta,int **iP,int nmom);
void spincolor_copy(spincolor b,spincolor a);
void spincolor_prod_double(spincolor out,spincolor in,double factor);
void spincolor_put_to_zero(spincolor m);
void spincolor_subt(spincolor a,spincolor b,spincolor c);
void spincolor_subtassign(spincolor a,spincolor b);
void spincolor_summ(spincolor a,spincolor b,spincolor c);
void spincolor_summ_the_prod_complex(spincolor out,spincolor in,complex factor);
void spincolor_summ_the_prod_double(spincolor a,spincolor b,spincolor c,double factor);
void spincolor_summassign(spincolor a,spincolor b);
void spinspin_dirac_spinspin_prod(spinspin out,dirac_matr *m,spinspin in);
void spinspin_dirac_spinspin_prod_transp(spinspin out,dirac_matr *m,spinspin in);
void spinspin_dirac_spinspindag_prod(spinspin out,dirac_matr *m,spinspin in);
void spinspin_spinspin_prod(spinspin out,spinspin a,spinspin b);
void spinspin_spinspindag_prod(spinspin out,spinspin a,spinspin b);
void split_lx_color_into_eo_parts(color **eo_out,color *lx_in,int nsites);
void split_lx_conf_into_eo_parts(quad_su3 **eo_out,quad_su3 *lx_in,int nsites);
void split_lx_spincolor_into_eo_parts(spincolor **eo_out,spincolor *lx_in,int nsites);
void split_lx_vector_into_eo_parts(char *out_ev,char *out_od,char *in_lx,int nsites,int bps);
void squared_path(su3 square,quad_su3 *conf,int A,int mu,int nu);
void start_loc_rnd_gen(int seed);
void start_rnd_gen(rnd_gen *out,int seed);
void stop_loc_rnd_gen();
void su3_copy(su3 b,su3 a);
void su3_dag_subt_the_prod_color(color a,su3 b,color c);
void su3_dag_summ_the_prod_color(color a,su3 b,color c);
void su3_det(complex d,su3 U);
void su3_hermitian_prod_double(su3 a,su3 b,double r);
void su3_print(su3 U);
void su3_prod_double(su3 a,su3 b,double r);
void su3_prod_with_idouble(su3 a,su3 b,double r);
void su3_put_to_id(su3 m);
void su3_put_to_zero(su3 m);
void su3_subt(su3 a,su3 b,su3 c);
void su3_subt_complex(su3 a,su3 b,complex c);
void su3_subt_the_prod_color(color a,su3 b,color c);
void su3_summ(su3 a,su3 b,su3 c);
void su3_summ_real(su3 a,su3 b,double c);
void su3_summ_the_prod_color(color a,su3 b,color c);
void su3_summ_the_prod_double(su3 a,su3 b,double r);
void su3_summ_the_prod_spincolor(spincolor out,su3 U,spincolor in);
void su3_trace(complex tr,su3 m);
void su3_traceless_anti_hermitian_part(su3 out,su3 in);
void su3_unitarize_explicitly_inverting(su3 new_link,su3 prop_link);
void su3_unitarize_maximal_trace_projecting(su3 U,su3 M);
void su3_unitarize_maximal_trace_projecting_iteration(su3 U,su3 M);
void su3_unitarize_orthonormalizing(su3 o,su3 i);
void su3_vec_single_shift(su3 *u,int mu,int sign);
void su3spinspin_put_to_zero(su3spinspin m);
void sum_trace_g_sdag_g_s_times_trace_g_sdag_g_s(complex **glb_c, dirac_matr *g1L,colorspinspin *s1L, dirac_matr *g2L, colorspinspin *s2L, dirac_matr *g1R,colorspinspin *s1R, dirac_matr *g2R, colorspinspin *s2R,const int ncontr);
void sum_trace_id_sdag_g_s_times_trace_id_sdag_g_s(complex *glb_c,colorspinspin *s1L,dirac_matr *g2L,colorspinspin *s2L,colorspinspin *s1R,dirac_matr *g2R,colorspinspin *s2R,const int ncontr);
void summ_src_and_all_inv_stD2ee_cgmm2s(color *sol,color *source,quad_su3 **conf,rat_approx *appr,int niter,double st_res,double st_minres,int st_crit);
void summ_the_trace_g_sdag_g_s(complex *glb_c,dirac_matr *g1,colorspinspin *s1,dirac_matr *g2,colorspinspin *s2,const int ncontr);
void summ_the_trace_prod_dirac_spinspin(complex c,dirac_matr *a,spinspin b);
void summ_the_trace_prod_spinspins(complex c,spinspin a,spinspin b);
void swap_doubles(double *d1,double *d2);
void swap_eo_to_lx(char *out_lx,char *in_e,char *in_o,int nbytes_per_site,int bord);
void swap_lx_to_eo(char *out_e,char *out_o,char *in_lx,int nbytes_per_site,int bord);
void swap_lx_to_eo_or_eo_to_lx(char *vect_e,char *vect_o,char *vect_lx,int nbytes_per_site,int bord,int eotolx_lxtoeo);
void swap_spincolor_eo_to_lx(spincolor *out_lx,spincolor *in_e,spincolor *in_o,int bord);
void swap_spincolor_lx_to_eo(spincolor *out_e,spincolor *out_o,spincolor *in_lx,int bord);
void take_e_or_o_part_of_lx_vector(char *out_e_or_o,char *in_lx,int nsites,int bps,int par);
void take_e_part_of_lx_color(color *out_e,color *in_lx,int nsites);
void take_e_part_of_lx_vector(char *out_e,char *in_lx,int nsites,int bps);
void take_last_characters(char *out,const char *in,int size);
void take_o_part_of_lx_color(color *out_o,color *in_lx,int nsites);
void take_o_part_of_lx_vector(char *out_o,char *in_lx,int nsites,int bps);
void terminate_sigsegv(int par);
void tmDee_or_oo_eos(spincolor *out,spincolor *in,double kappa,double mu);
void tmDkern_eoprec_eos(spincolor *out,spincolor *temp,spincolor *in,quad_su3** conf,double kappa,double mu);
void tmDkern_eoprec_square_eos(spincolor *out,spincolor *temp1,spincolor *temp2,spincolor *in,quad_su3 **conf,double kappa,double mu);
void tmn2Deo_eos(spincolor *out,spincolor *in,quad_su3 **conf);
void tmn2Deo_or_tmn2Doe_eos(spincolor *out,spincolor *in,quad_su3 **conf,int eooe);
void tmn2Doe_eos(spincolor *out,spincolor *in,quad_su3 **conf);
void trace_g_ccss_dag_g_ccss(complex *glb_c,dirac_matr *g1,su3spinspin *s1,dirac_matr *g2,su3spinspin *s2,const int ncontr);
void trace_g_sdag_g_s(complex *glb_c,dirac_matr *g1,colorspinspin *s1,dirac_matr *g2,colorspinspin *s2,const int ncontr);
void trace_g_sdag_g_s_g_sdag_g_s(complex **glb_c, dirac_matr *g1L,colorspinspin *s1L, dirac_matr *g2L, colorspinspin *s2L, dirac_matr *g1R,colorspinspin *s1R, dirac_matr *g2R, colorspinspin *s2R,const int ncontr);
void trace_id_sdag_g_s_id_sdag_g_s(complex *glb_c,colorspinspin *s1L,dirac_matr *g2L,colorspinspin *s2L,colorspinspin *s1R,dirac_matr *g2R,colorspinspin *s2R,const int ncontr);
void trace_prod_dirac_spinspin(complex c,dirac_matr *a,spinspin b);
void trace_prod_spinspins(complex c,spinspin a,spinspin b);
void unsafe_apply_chromo_operator_to_colorspinspin(colorspinspin *out,as2t_su3 *Pmunu,colorspinspin *in);
void unsafe_apply_chromo_operator_to_spincolor(spincolor *out,as2t_su3 *Pmunu,spincolor *in);
void unsafe_apply_chromo_operator_to_su3spinspin(su3spinspin *out,as2t_su3 *Pmunu,su3spinspin *in);
void unsafe_apply_point_chromo_operator_to_spincolor(spincolor out,as2t_su3 Pmunu,spincolor in);
void unsafe_color_prod_complex(color out,color in,complex factor);
void unsafe_color_prod_complex_conj(color out,color in,complex factor);
void unsafe_color_prod_su3(color a,color b,su3 c);
void unsafe_color_prod_su3_dag(color a,color b,su3 c);
void unsafe_complex_conj1_prod(complex a,complex b,complex c);
void unsafe_complex_conj1_prod_minus(complex a,complex b,complex c);
void unsafe_complex_conj2_prod(complex a,complex b,complex c);
void unsafe_complex_conj2_prod_minus(complex a,complex b,complex c);
void unsafe_complex_conj_conj_prod(complex a,complex b,complex c);
void unsafe_complex_conj_conj_prod_minus(complex a,complex b,complex c);
void unsafe_complex_prod(complex a,complex b,complex c);
void unsafe_complex_prod_minus(complex a,complex b,complex c);
void unsafe_dirac_compl_prod(dirac_matr *out,dirac_matr *in,complex c);
void unsafe_dirac_prod_spincolor(spincolor out,dirac_matr *m,spincolor in);
void unsafe_spincolor_prod_complex(spincolor out,spincolor in,complex factor);
void unsafe_spincolor_prod_dirac(spincolor out,spincolor in,dirac_matr *m);
void unsafe_spincolor_summ_with_ifactor(spincolor out,spincolor a,spincolor b,double factor);
void unsafe_spincolor_summassign_the_prod_idouble(spincolor out,spincolor in,double factor);
void unsafe_su3_dag_dirac_prod_spincolor(spincolor out,su3 U,dirac_matr *m,spincolor in);
void unsafe_su3_dag_dirac_summ_the_prod_spincolor(spincolor out,su3 U,dirac_matr *m,spincolor in);
void unsafe_su3_dag_prod_color(color a,su3 b,color c);
void unsafe_su3_dag_prod_spincolor(spincolor out,su3 U,spincolor in);
void unsafe_su3_dag_prod_su3(su3 a,su3 b,su3 c);
void unsafe_su3_dag_prod_su3_dag(su3 a,su3 b,su3 c);
void unsafe_su3_dag_summ_the_prod_spincolor(spincolor out,su3 U,spincolor in);
void unsafe_su3_dirac_prod_spincolor(spincolor out,su3 U,dirac_matr *m,spincolor in);
void unsafe_su3_dirac_subt_the_prod_spincolor(spincolor out,su3 U,dirac_matr *m,spincolor in);
void unsafe_su3_explicit_inverse(su3 invU,su3 U);
void unsafe_su3_hermitian(su3 out,su3 in);
void unsafe_su3_prod_color(color a,su3 b,color c);
void unsafe_su3_prod_complex(su3 a,su3 b,complex c);
void unsafe_su3_prod_conj_complex(su3 a,su3 b,complex c);
void unsafe_su3_prod_spincolor(spincolor out,su3 U,spincolor in);
void unsafe_su3_prod_su3(su3 a,su3 b,su3 c);
void unsafe_su3_prod_su3_dag(su3 a,su3 b,su3 c);
void unsafe_su3_taylor_exponentiate(su3 out,su3 in,int order);
void unsafe_su3spinspin_prod_complex(su3spinspin out,su3spinspin in,complex factor);
void unset_eo_geometry();
void unset_lx_geometry();
void vector_gather(void *glb,void *loc,int bps,int dest_rank);
void vol_spincolor_prod_double(spincolor *out,spincolor *in,double r);
void vol_spincolor_summassign(spincolor *smear_sc,spincolor *H);
void write_checksum(LemonWriter *writer,checksum check);
void write_color(char *path,color *v,int prec);
void write_double_vector(LemonWriter *writer,char *data,char *header_message,int nreals_per_site,int nbits);
void write_gauge_conf(char *path,quad_su3 *in);
void write_header(LemonWriter *writer,char *header,uint64_t record_bytes);
void write_spincolor(char *path,spincolor *spinor,int prec);
void write_su3spinspin(char *path,su3spinspin *prop,int prec);
void write_text_record(LemonWriter *writer,char *header,char *message);
void* nissa_true_free(void *arr,const char *file,int line);
