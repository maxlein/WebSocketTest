#!/usr/bin/env groovy

pipeline {
  agent any
    options {
        buildDiscarder(logRotator(numToKeepStr: '5', artifactNumToKeepStr: '5'))
        timeout(time: 1, unit: 'HOURS')
    }
  stages {
      stage('Clean workspace') {
          steps {
              /* Running on a fresh Docker instance makes this redundant, but just in
          * case the host isn't configured to give us a new Docker image for every
          * build, make sure we clean things before we do anything
          */

              deleteDir()
              sh 'ls -lah'
          }
      }
      stage('Checkout source') {
          steps {
              checkout scm
          }
      }
    stage('Build') {
      steps {
          timeout(30) {
              sh 'mkdir -p build && cd build && cmake .. && make'
          }
      }
    }
    stage('Test') {
      steps {
        sh ' cd build && tests/testfoo --gtest_output="xml:testresults.xml" && mkdir reports && mv testresults.xml reports/ '
        echo 'ls: $(ls)'
      }
    }
    stage('Artifact') {
      steps {
          sh 'ls -lah'
        archiveArtifacts(onlyIfSuccessful: true, artifacts: 'build/bin/*, bin/*')
      }
    }
  }
  post {
    always {
      junit 'build/reports/*.xml'

    }

  }
}