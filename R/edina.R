#' Construct an EDINA object
#'
#' Constructor function to satisfy the EDINA object definition
#' @param coefs          Matrix with means of guessing and slipping coefficients.
#' @param loglike_summed Log-likelihood over the iterations.
#' @param loglike_pmean  Log-likelihood at the mean point
#' @param pis            Estimated latent classes
#' @param avg_q          Averaged Q Matrix over Iterations
#' @param est_q          Estimated Q Matrix
#' @param or_tested      Sample empirical odds ratio compared against simulated
#'                       odds ratio divided by the number of simulations.
#' @param sample_or      Sample empirical odds ratio based on the trial matrix.
#' @inheritParams edina
#' @param n            Number of Observations
#' @param timing       Number of Seconds that have elapsed since run time.
#' @param dataset_name Name of the data set the estimation procedure ran on.
#' @keywords internal
new_edina = function(coefs, loglike_summed, loglike_pmean,
                     pis, avg_q, est_q, or_tested, sample_or, n, burnin,
                     chain_length,  timing, dataset_name) {

    colnames(coefs) = c("Guessing", "SD(Guessing)", "Slipping", "SD(Slipping)")
    rownames(coefs) = paste0("Item", seq_len(nrow(coefs)) )

    est_q = format_q_matrix(est_q)
    avg_q = format_q_matrix(avg_q)

    structure(list("coefficients"   = coefs,
                   "loglike_summed" = loglike_summed,
                   "loglike_pmean"  = loglike_pmean,
                   "pi_classes"     = pis,
                   "avg_q"          = avg_q,
                   "est_q"          = est_q,
                   "or_tested"      = or_tested,
                   "sample_or"      = sample_or,
                   "n"              = n,
                   "j"              = nrow(est_q),
                   "k"              = ncol(est_q),
                   "burnin"         = burnin,
                   "chain_length"   = chain_length,
                   "timing"         = timing,
                   "dataset_name"   = dataset_name),
                   class = "edina")
}


#' Construct a Summary EDINA object
#'
#' Constructor function to satisfy the Summary EDINA object definition
#' @param edina      An `edina` object
#' @param model_fit  Computed model heuristic value
#' @param alpha      The region used in the computation of the heuristic.
#' @keywords internal
new_edina_summary = function(edina, model_fit, alpha) {

    edina[["model_fit"]] = model_fit
    edina[["alpha"]] = alpha

    class(edina) = c("summary_edina", "edina")

    edina
}


#' Model Heuristic used for Model Selection
#'
#' Computes the model heuristic for model selection.
#' @inheritParams summary.edina
#' @return A `double` that is the mean.
#' @export
model_heuristic = function(object, alpha = 0.05) {
    or_tested = object$or_tested

    mean(or_tested[upper.tri(or_tested)] < alpha |
         or_tested[upper.tri(or_tested)] > (1-alpha))
}

#' Compute the Deviance Information Criterion (DIC)
#'
#' Calculate DIC for EDINA models.
#'
#' @param object An `edina` object
#' @param ... Not used.
#' @rdname DIC
#' @export
DIC = function(object, ...) {
    UseMethod("DIC")
}

#' @rdname DIC
#' @export
DIC.edina = function(object, ...) {

    # LogLikelihood at the Mean of the Posterior Distributioon
    L = object$loglike_pmean

    # Number of parameters in the model
    P = 2 * (L - (1 / object$chain_length * object$loglike_summed))

    -2 * (L - P)
}


## 2 * K - I_K fixed allothers to 1's. Then estimate R* matrix and the J pi*

#' Calculate BIC for EDINA models.
#' @param object An `edina` object
#' @param ... Not used.
#' @export
#' @importFrom stats BIC
BIC.edina = function(object, ...) {
    # K number of attributes and J number of items (count only one slipping/guessing)?
    # -2 * LogLike + ln(n) * (k + j)
    -2*object$loglike_pmean + log(object$n)*((object$k+2)*object$j + 2^object$k)
}

#' EDINA estimation routine
#'
#' Exploratory Determinatistic Input, Noise and Gate Model (EDINA)
#'
#' @param data         Binary responses to assessements in `matrix`
#'                     form with dimensions \eqn{N \times J}{N x J}.
#' @param k            Number of Attribute Levels as a positive `integer`.
#' @param burnin       Number of Observations to discard on the chain.
#' @param chain_length Length of the MCMC chain
#'
#' @return An `edina` object that contains:
#'
#' - `coefficients`: Estimated coefficients of the model fit
#' - `loglike_summed`: Summed log-likelihood
#' - `loglike_pmean`: Meaned version of log-likelihood
#' - `pi_classes`: Latent classes
#' - `avg_q`: Estimated Averaged Q Matrix
#' - `est_q`: Estimated Dichotomous Q Matrix
#' - `or_tested`: Odds Ratio used in the model selection.
#' - `sample_or`: Odds Ratio for the sample.
#' - `n`: Number of Observations
#' - `j`: Number of Items
#' - `k`: Number of Traits
#' - `burnin`: Amount of iterations to discard
#' - `chain_length`: Amount of iterations to retain.
#' - `timing`: Duration of the run
#' - `dataset_name`: Name of the data set used in estimation.
#' @export
#' @importFrom jjb is_whole
#' @examples
#' \dontrun{
#' library("tmsadata")
#'
#' # Load data
#' data("trial_matrix", package="tmsadata")
#'
#' # Coerce to matrix
#' trial_matrix = as.matrix(trial_matrix)
#'
#' edina_model = edina(trial_matrix, k = 2)
#' }
#'
edina = function(data, k = 3, burnin = 10000, chain_length = 20000){

    stopifnot(is.matrix(data))

    stopifnot(is_whole(k) && length(k) == 1 && k >= 1)

    stopifnot(is_whole(chain_length) && length(chain_length) == 1)

    time_info = system.time({

        edina_model = edina_Gibbs_Q(data, k,
                                    burnin = burnin,
                                    chain_length = chain_length)

    })[1:3]

    dataset_name = deparse(substitute(data))

    new_edina(edina_model$coefficients,
              edina_model$loglike_summed,
              edina_model$loglike_pmean,
              edina_model$pis,
              edina_model$avg_q,
              edina_model$est_q,
              edina_model$or_tested,
              edina_model$sample_or,
              nrow(data),
              burnin, chain_length,
              time_info,
              dataset_name
              )
}

#' Printing out the EDINA Object
#'
#' Custom print method for computing the EDINA.
#'
#' @param x        An `edina` object
#' @param binary_q Boolean to indicate whether the _Q_ matrix is shown in
#'                 dichotomous form or in an estimated form.
#' @param ...      Additional methods passed onto the `print.matrix` method.
#'
#' @export
print.edina = function(x, binary_q = FALSE, ...){
    cat("The EDINA model for", x$dataset_name, "with K =", x$k,"took\n",
        format(convert_seconds_to_time(x$timing[3])), "\n\n")

    est_mat = cbind(extract_q_matrix(x, binary_q = binary_q), x$coefficients)

    print(est_mat, digits = 4, ...)
    invisible(est_mat)
}

#' Summarizing the EDINA Object
#'
#' Determine whether the `edina` object is summarized appropriately.
#'
#' @param object An `edina` object
#' @param alpha  Defining region to indicate the level of extremeness
#'               the data must before the model is problematic.
#' @param ...    Not used.
#'
#' @export
summary.edina = function(object, alpha = 0.05, ...) {

    model_fit = matrix(c(object$k, BIC(object), DIC(object),
                         model_heuristic(object, alpha)), ncol = 4)

    colnames(model_fit) = c("k", "bic", "dic", "heuristic")

    new_edina_summary(
        object,
        model_fit = model_fit,
        alpha = alpha
    )

}

#' Printing out the Summary EDINA Object
#'
#' Custom print method for displaying the EDINA model summary information.
#'
#' @param x        A `summary_edina` object
#' @param binary_q Boolean to indicate whether the _Q_ matrix is shown in
#'                 dichotomous form or in an estimated form.
#' @param ...      Past onto the `print.data.frame` method.
#'
#' @export
print.summary_edina = function(x, binary_q = FALSE,  ...) {
    # Rely upon the specification of the `edina` object in the summary class.
    # NextMethod()

    cat("The EDINA model for", x$dataset_name, "with K =", x$k,
        "\ntook", format(convert_seconds_to_time(x$timing[3])), "\n")

    cat("\nThe model fit is as follows:\n")
    print(as.data.frame(x$model_fit), row.names = FALSE)

    cat("\nThe estimated coefficients for the EDINA model are:\n")
    print(x$coefficients, digits = 4)

    cat("\nThe estimated Q matrix is:\n")
    print(extract_q_matrix(x, binary_q = binary_q), digits = 4)

    invisible(x)
}
