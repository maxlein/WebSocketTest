pipeline {
  agent any
  stages {
    stage('Clean workspace') {
      steps {
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
        timeout(time: 30) {
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
      parallel {
        stage('Artifact') {
          steps {
            sh 'ls -lah'
            archiveArtifacts(onlyIfSuccessful: true, artifacts: 'build/bin/*, bin/*')
          }
        }
        stage('Code Analysis') {
          steps {
            sh '''cppcheck --xml --xml-version=2 . 2> cppcheck.xml
'''
          }
        }
      }
    }
  }
  post {
    always {
      junit 'build/reports/*.xml'

    }

  }
  options {
    buildDiscarder(logRotator(numToKeepStr: '5', artifactNumToKeepStr: '5'))
    timeout(time: 1, unit: 'HOURS')
  }
}