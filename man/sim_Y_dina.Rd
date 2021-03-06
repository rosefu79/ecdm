% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{sim_Y_dina}
\alias{sim_Y_dina}
\title{Simulate Binary Responses for DINA Model}
\usage{
sim_Y_dina(N, J, CLASS, ETA, gs, ss)
}
\arguments{
\item{N}{Number of Observations}

\item{J}{Number of Assessment Items}

\item{CLASS}{Does the individual possess all the necessary attributes?}

\item{ETA}{\eqn{\eta} Matrix containing indicators.}

\item{gs}{A \code{vec} describing the probability of guessing or
the probability subject correctly answers item \eqn{j} when at
least one attribute is lacking.}

\item{ss}{A \code{vec} describing the probability of slipping or
the probability of an incorrect response for individuals with
all of the required attributes}
}
\value{
A \code{mat}
}
\description{
Simulation the Y Response for a DINA Model
}
