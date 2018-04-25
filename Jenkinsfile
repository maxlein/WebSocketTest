#!groovy​

pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'mkdir build && cd build && cmake .. && make'
      }
    }
    stage('Test') {
      steps {
        sh ' cd build && tests/testfoo --gtest_output="xml:testresults.xml" && mkdir reports && mv testresults.xml reports/ '
      }
    }
    stage('Artifact') {
      steps {
        archiveArtifacts(onlyIfSuccessful: true, artifacts: 'build/bin/*')
      }
    }
  }
  post {
    always {
      junit 'build/reports/*.xml'

    }

  }
}
